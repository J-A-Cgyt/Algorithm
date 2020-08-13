#include <stdio.h>

//节点序计算宏定义
#define LEFT(i) (i<<1)-1;        //左节点序计算
#define RIGHT(i) i<<1;   //右节点序计算
#define FATHER(i) i>>1;      //父节点序计算

int Data[10] = { 1,53,2,6,32,31,8,64,9,45 };

void MAX_heapify(int* data, int i, int len);

int main()
{
	for (int i = 4; i >= 0; i--)
	{
		MAX_heapify(Data, i, 10);	
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", Data[i]);
		}
		printf("\n");
	}

	return 0;
}

void MAX_heapify(int* data, int i, int len)  //最大堆的维护 20200812
{
	i = i + 1;
	int left = LEFT(i);
	int right = RIGHT(i);
	i = i - 1;
	int max;

	// printf("i=%d,left=%d,right=%d\n", i, left, right);
	
	if ((left<len) & (data[left]>data[i]))
	{
		max = left;
	}
	else
	{
		max = i;
	}
	if ((right<len) & (data[right]>data[max]))
	{
		max = right;
	}
	if (max != i)
	{
		int temp;
		temp = data[max];
		data[max] = data[i];
		data[i] = temp;
		printf("%d,%d换位\n", max, i);
		MAX_heapify(data, max, len);
	}
}