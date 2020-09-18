#include <stdio.h>
#include <iostream>

int data[10] = { 2,34,6,54,57,97,4,5,10,74 };
int k = 100; //数组数值上限
int output[10];
int length = 10;

//计数排序，需要获知数组的最大值，若数值太大或连续则不适用
int main()
{
	//计数排序
	int c[100];
	for (int i = 0; i < k; i++)  //临时数组初始化
	{
		c[i] = 0;
	}
	for (int i = 0; i < length; i++)  //data中等于特定数值的元素量统计
	{
		c[data[i]] += 1;
	}
	for (int i = 1; i < k; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	for (int i = length-1; i >= 0; i--)
	{
		output[c[data[i]-1]] = data[i];
		c[data[i]] = c[data[i]] - 1;
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d,", output[i]);
	}
	
	//基数排序

}