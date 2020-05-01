//�㷨����ʵ��2�������㷨�е�������������⡣�տ�ʼ�ȹ涨һ�������
#include <iostream>

//�ඨ��
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
//�෽��ʵ��
void MinSubArray_Info::showInfo()
{
	std::cout << "������ǰ�±�" << this->minLabel << std::endl;
	std::cout << "��������±�" << this->maxLabel << std::endl;
	std::cout << "�������" << this->Sum << std::endl;
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
	//�����������Ѱ
	int left_sum = -9999;  //ʵ����Ӧ����-��
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
	//�����������Ѱ
	int right_sum = -9999;  //ʵ����Ӧ����-��
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

	//�����֯
	MinSubArray_Info Res;
	Res.SetInfo(max_left,max_right,Cross_Sum);
	return Res;
}
//�ݹ�ķ���
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

	//�ǵݹ�ķ�������
	MinSubArray_Info Res_2, Border;
	Res_2.SetInfo(0, 0, A[0]);
	Border.SetInfo(0, 0, A[0]);
	int sum_temp = 0;
	int sum = 0;
	/*���Է���ʵ��20200501��ע�������ȽϺ͵�Ч���Լ��Ѿ�������������ĸ��ã�
	��CSDN�������������Ǻϡ�������֮ǰ�ļ����������ж�����˼��ٹ�������
	�Խ����㷨�������ԣ��ù�ģ��С�������������ʼ����һ���Ϻõ�˼·��Դ
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
