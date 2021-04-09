#include <stdio.h>
#include <math.h>
#include <map>
//用来计算zernike多项式的小东西

int m, n;  //zernike多项式的的参数 其中n>m
double R_xishu, R_zhishu;
std::map<double, double> xiang;  //关键字为ρ的指数 值为系数

int jiecheng(const int &start) {  //递归不能输入字面值也就是说右值不行？ 否则全是0 改成循环倒是可以 必然是多次调用的时候导致变量信息被省去了一部分 也不是 似乎和数据类型有关
	if (start == 1 || start == 0) {
		return 1; 
	}
	else {
		int x = 1;
		for (int k = start; k > 1; k--) {
			x = x * k;
		}
		return x;
		//printf("%d\n", start);
		//return start * jiecheng(start - 1);
	}
}

//看来double在做这种阶乘的时候似乎有问题 而且是极其底层的问题 暂时放一放吧 如果不同的数据类型导致了不同的结果 那就只能说明 问题可能甚至不是我写的锅
double test(const double &start) {
	if (start == 1 || start == 0) {
		return 1;
	}
	else {
		//printf("%d\n", start);
		return start * jiecheng(start - 1);
	}
}


int main() {

	n = 3, m = -1;

	if ((n - m) % 2 == 1) {
		R_xishu = 0;
		R_zhishu = 1;
	}
	else {
		int k = 0;
		for (; k <= ((n - m) / 2); k++) {
			R_zhishu = n - 2 * k;
			int fenmu, fenzi;
			fenzi = pow(-1, k) * jiecheng(n - k);
			int q[3];
			q[0] = jiecheng(k);
			q[1] = jiecheng((n + m) / 2 - k);
			q[2] = jiecheng((n - m) / 2 - k);
			fenmu = q[0] * q[1] * q[2];
			R_xishu = fenzi / fenmu;
			xiang[R_zhishu] = R_xishu;
		}
	}

	double s = 0.0;
	s = test(4.0);
	printf("%d\n", s);
	return 0;
}