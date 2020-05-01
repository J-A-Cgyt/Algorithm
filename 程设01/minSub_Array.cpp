//算法导论实现2，分治算法中的最大子数组问题。刚开始先规定一个数组吧
#include <iostream>

//类定义
class MinSubArray_Info
{
public:
	void showInfo();
	void SetInfo(int min,int max,int sum);
	int GetMin();
	int GetMax();
private:
	int minLabel;
	int maxLabel;
public:
	int Sum;
};
//类方法实现
void MinSubArray_Info::showInfo()
{
	std::cout << "子数组前下标" << this->minLabel << std::endl;
	std::cout << "子数组后下标" << this->maxLabel << std::endl;
	std::cout << "子数组和" << this->Sum << std::endl;
}

void MinSubArray_Info::SetInfo(int min, int max, int sum)
{
	this->maxLabel = max;
	this->minLabel = min;
	this->Sum = sum;
}

int MinSubArray_Info::GetMin()
{
	return minLabel;
}

int MinSubArray_Info::GetMax()
{
	return maxLabel;
}

MinSubArray_Info FindSubarrayCross(int *ArrayPt, int low,int mid,int high)
{
	//左最大子数组寻
	int left_sum = -9999;  //实际上应该是-∞
	int sum = 0;
	int max_left = 0;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + ArrayPt[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	//右最大子数组寻
	int right_sum = -9999;  //实际上应该是-∞
	sum = 0;
	int max_right = 0;
	for (int i = mid+1; i <= high; i++)
	{
		sum = sum + ArrayPt[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	int Cross_Sum;
	Cross_Sum = left_sum + right_sum;

	//结果组织
	MinSubArray_Info Res;
	Res.SetInfo(max_left,max_right,Cross_Sum);
	return Res;
}
//递归的方法
MinSubArray_Info FindMaxSubArray(int* ArrayPt, int low, int high)
{
	if (high == low)
	{
		MinSubArray_Info res;
		res.SetInfo(low, high, ArrayPt[low]);
		res.showInfo();
		return res;
	}
	else
	{
		int mid = (low + high) / 2;

		MinSubArray_Info resL = FindMaxSubArray(ArrayPt, low, mid);
		MinSubArray_Info resR = FindMaxSubArray(ArrayPt, mid + 1, high);
		MinSubArray_Info resC = FindSubarrayCross(ArrayPt, low, mid, high);

		if ((resL.Sum > resC.Sum) & (resL.Sum > resR.Sum))
		{
			resL.showInfo();
			return resL;
		}
		else if ((resC.Sum > resL.Sum) & (resC.Sum > resR.Sum))
		{
			resC.showInfo();
			return resC;
		}
		else
		{
			resR.showInfo();
			return resR;
		}
	}
}

int main()
{
	int A[10];
	//A[0] = 3; A[1] = -2; A[2] = 9; A[3] = -1; A[4] = 2; A[5] = 7; A[6] = -12; A[7] = 13; A[8] = -6; A[9] = 1;
	A[0] = 3; A[1] = 6; A[2] = -10; A[3] = 1; A[4] = 2; A[5] = 7; A[6] = -8; A[7] = 13; A[8] = -6; A[9] = 1;
	MinSubArray_Info res;
	res = FindMaxSubArray(A, 0, 9);
	res.showInfo();

	//非递归的方法尝试
	MinSubArray_Info Res_2, Border;
	Res_2.SetInfo(0, 0, A[0]);
	Border.SetInfo(0, 0, A[0]);
	int sum_temp = 0;
	int sum = 0;
	/*线性方法实现20200501，注意条件比较和等效，以及已经计算过的条件的复用！
	和CSDN昨晚看见的文章吻合——利用之前的计算结果进行判定并借此减少工作量。
	对进行算法分析而言，用规模较小的问题进行试验始终是一个较好的思路来源
	*/for (int i = 1; i < 10; i++)
	{
		if (Border.Sum + A[i] < A[i])
		{
			Border.SetInfo(i, i, A[i]);
		}
		else 
		{
			Border.SetInfo(Border.GetMin(), i, Border.Sum + A[i]);
		}

		if (Border.Sum > Res_2.Sum)
		{
			Res_2.SetInfo(Border.GetMin(), Border.GetMax(), Border.Sum);
		}
	}

	return 0;
}
