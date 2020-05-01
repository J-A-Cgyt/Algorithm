#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <iostream>
#include <vector>
//#include <thread>

using namespace cv;

template <typename _Tp>
_Tp* Sort_cgyt(_Tp* Queue, int size, std::vector<_Tp> A, std::vector<_Tp> B);

template <typename _Tp>
_Tp* Merge_cgyt(_Tp* Queue, std::vector<_Tp> A, std::vector<_Tp> B);

/*
double* Sort_cgyt(double* Queue, int size, std::vector<double> A, std::vector<double> B);
double* Merge_cgyt(double* Queue, std::vector<double> A, std::vector<double> B);
*/
//20200304 尝试一下归并排序的实现,问题来源：算法导论 20200305实现完成，找时间整成模板函数 20200306模板函数改造完成
int main()
{
	int num;
	std::cout << "输入排序个数";
	std::cin >> num;

	int queue[1000];
	int* res;
	for (int i = 0; i < num; i++)
	{
		std::cin >> queue[i];
	}
	std::vector<int> A, B;

	res = Sort_cgyt(queue, num, A, B);
	for (int i = 0; i < num; i++)
	{
		std::cout << res[i] << "";
	}
	std::cout << std::endl;

	return 0;
}
//使用模板类的重载函数
template <typename _Tp>
_Tp* Sort_cgyt(_Tp* Queue, int size, std::vector<_Tp> A, std::vector<_Tp> B)
{
	std::vector<_Tp> a, b;
	_Tp* res;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			B.push_back(Queue[i]);
		else
			A.push_back(Queue[i]);
	}

	//递归，子问题重复调用
	if (A.size() > 1)
		Sort_cgyt(A.data(), A.size(), a, b);
	if (B.size() > 1)
		Sort_cgyt(B.data(), B.size(), a, b);
	//子问题合并
	res = Merge_cgyt<_Tp>(Queue, A, B);
	return res;
}

template <typename _Tp>
_Tp* Merge_cgyt(_Tp* Queue, std::vector<_Tp> A, std::vector<_Tp> B)
{
	_Tp temp;
	temp = A[0];
	_Tp* res = new _Tp[A.size() + B.size()];
	//res[0] = -1;
	//std::vector<double>::iterator Ptr_cgyt;

	//是否选择的标记
	bool* used_A = new bool[A.size()];
	bool* used_B = new bool[B.size()];
	for (int i = 0; i < A.size(); i++)
		used_A[i] = false;
	for (int i = 0; i < B.size(); i++)
		used_B[i] = false;

	for (int j = 0; j < A.size() + B.size(); j++)
	{
		//选择循环
		for (int i = 0; i < A.size() + B.size(); i++)
		{
			if (i < A.size())
			{
				if (temp > A[i]& (!used_A[i]))
				{
					temp = A[i];
					//used_A[i] = true;
					//A[i] = 10
				};
			}
			else
			{
				if ((temp > B[i - A.size()]) & (!used_B[i - A.size()]))
				{
					temp = B[i - A.size()];
					//used_B[i - A.size()] = true;
					//B[i - A.size()] = 10;
					//Ptr_cgyt = B.begin() + i - A.size();
					//B.erase(Ptr_cgyt);
				}
			}

		}
		//标记循环
		for (int i = 0; i < A.size() + B.size(); i++)
		{
			if (i < A.size())
			{
				if (temp == A[i])
				{
					used_A[i] = true;
				};
			}
			else
			{
				if ((temp == B[i - A.size()]))
				{
					used_B[i - A.size()] = true;
				}
			}

		}
		res[j] = temp;
		//res[j + 1] = temp;
		temp = 10;
	}

	for (int i = 0; i < A.size() + B.size(); i++)
	{
		std::cout << res[i] << "";
	}
	std::cout << std::endl;

	return res;
}

/*
double* Sort_cgyt(double* Queue, int size, std::vector<double> A, std::vector<double> B)
{
	std::vector<double> a, b;
	double* res;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			B.push_back(Queue[i]);
		else
			A.push_back(Queue[i]);

	}
	
	//递归，子问题重复调用
	if (A.size() > 1)
		Sort_cgyt(A.data(), A.size(), a, b);
	if (B.size() > 1)
		Sort_cgyt(B.data(), B.size(), a, b);
	res = Merge_cgyt(Queue, A, B);
	return res;
}

double* Merge_cgyt(double* Queue, std::vector<double> A, std::vector<double> B)
{
	double temp;
	temp = A[0];
	double* res = new double[A.size() + B.size()];
	//res[0] = -1;
	//std::vector<double>::iterator Ptr_cgyt;
	
	//是否选择的标记
	bool* used_A = new bool[A.size()];
	bool* used_B = new bool[B.size()];
	for (int i = 0; i < A.size(); i++)
		used_A[i] = false;
	for (int i = 0; i < B.size(); i++)
		used_B[i] = false;

	for (int j = 0; j < A.size() + B.size(); j++)
	{
		//选择循环
		for (int i = 0; i < A.size() + B.size(); i++)
		{
			if (i < A.size())
			{
				if (temp > A[i]& (!used_A[i]))
				{
					temp = A[i];
					//used_A[i] = true;
					//A[i] = 10
				};
			}
			else
			{
				if ((temp > B[i - A.size()]) & (!used_B[i - A.size()]))
				{
					temp = B[i - A.size()];
					//used_B[i - A.size()] = true;
					//B[i - A.size()] = 10;
					//Ptr_cgyt = B.begin() + i - A.size();
					//B.erase(Ptr_cgyt);
				}
			}

		}
		//标记循环
		for (int i = 0; i < A.size() + B.size(); i++)
		{
			if (i < A.size())
			{
				if (temp == A[i])
				{					
					used_A[i] = true;
				};
			}
			else
			{
				if ((temp == B[i - A.size()]))
				{
					used_B[i - A.size()] = true;
				}
			}

		}
		res[j] = temp;
		//res[j + 1] = temp;
		temp = 10;
	}
	
	for (int i = 0; i < A.size() + B.size(); i++)
	{
		std::cout << res[i] << "";
	}
	std::cout << std::endl;

	return res;
*/