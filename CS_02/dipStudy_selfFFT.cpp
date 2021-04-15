#include "head.h"

using std::complex;   //STL复数模板
using std::vector;	  

/*
自行尝试的FFT方法，返回复数序列 
有感觉内存消耗会很恐怖 此处限制一下信号长度必须是2的n次方 
否则三个的没办法处理 不然就得延拓
*/
vector<complex<double>> fft_CGYT(const vector<double>& signal) {
	size_t nSize(signal.size());
	vector<complex<double>> freqFunc(nSize); //总的频域函数

	//下面需要将信号拆半
	vector<double> signalO(nSize/2); //奇数部分信号
	vector<double> signalE(nSize/2); //偶数部分信号

	return freqFunc;
}