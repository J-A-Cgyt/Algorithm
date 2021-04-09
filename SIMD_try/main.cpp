#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <ctime>
#include "immintrin.h"
//#include "avxintrin.h"

int main() {
	__m256i intV1;
	__m256i intV2;
	__m256d doubleV1;
	__m256d doubleV2;
	for (int i = 0; i < 8; i++) {
		intV1.m256i_i32[i] = i;
		intV2.m256i_i32[i] = 100 * i;
	}
	intV2 = _mm256_add_epi32(intV1, intV2);

	cv::Mat Src, Dst;
	std::string LoadingPath("F:\\Pictures\\Test For Programming\\1.jpg");
	Src = cv::imread(LoadingPath, cv::IMREAD_GRAYSCALE);
	auto pData = Src.ptr();
	for (size_t i = 0; i < Src.total() * Src.elemSize(); i++) {
		intV1.m256i_i8[i % 8] = pData[i];
	}


	return 0;
}

//正常的逐个累加运算
double compute_pi_naive(size_t dt) {
	double pi = 0.0;
	double delta = 1.0 / dt;
	for (size_t i = 0; i < dt; i++) {
		double x = (double)i / dt;
		pi += delta / (1 + x * x);
	}
	return pi * 4.0;
}
//利用avx256指令集
double compute_pi_avx256(size_t dt) {
	double pi = 0.0;
	double delta = 1.0 / dt;
	__m256d ymm0, ymm1, ymm2, ymm3, ymm4;
	ymm0 = _mm256_set1_pd(1.0);
	ymm1 = _mm256_set1_pd(delta);
	ymm2 = _mm256_set_pd(delta * 3, delta * 2, delta, 0.0);
	ymm4 = _mm256_setzero_pd();
	for (int i = 0; i < dt - 4; i += 4) {
		ymm3 = _mm256_set1_pd(i*delta);
		ymm3 = _mm256_add_pd(ymm3, ymm2);
		ymm3 = _mm256_mul_pd(ymm3, ymm3);
		ymm3 = _mm256_add_pd(ymm0, ymm3);
		ymm3 = _mm256_div_pd(ymm1, ymm3);
		ymm4 = _mm256_add_pd(ymm4, ymm3);
	}
	 __declspec(align(32)) double tmp[4];// attribute((aligned(32))); ——GNU写法
	_mm256_store_pd(tmp, ymm4);
	pi += tmp[0] + tmp[1] + tmp[2] + tmp[3];
	return pi * 4.0;
}
