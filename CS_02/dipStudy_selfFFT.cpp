#include "head.h"

using std::complex;   //STL����ģ��
using std::vector;	  

/*
���г��Ե�FFT���������ظ������� 
�ио��ڴ����Ļ�ֲܿ� �˴�����һ���źų��ȱ�����2��n�η� 
����������û�취���� ��Ȼ�͵�����
*/
vector<complex<double>> fft_CGYT(const vector<double>& signal) {
	size_t nSize(signal.size());
	vector<complex<double>> freqFunc(nSize); //�ܵ�Ƶ����

	//������Ҫ���źŲ��
	vector<double> signalO(nSize/2); //���������ź�
	vector<double> signalE(nSize/2); //ż�������ź�

	return freqFunc;
}