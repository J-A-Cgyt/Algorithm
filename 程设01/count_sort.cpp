#include <stdio.h>
#include <iostream>

int data[10] = { 2,34,6,54,57,97,4,5,10,74 };
int k = 100; //������ֵ����
int output[10];
int length = 10;

//����������Ҫ��֪��������ֵ������ֵ̫�������������
int main()
{
	//��������
	int c[100];
	for (int i = 0; i < k; i++)  //��ʱ�����ʼ��
	{
		c[i] = 0;
	}
	for (int i = 0; i < length; i++)  //data�е����ض���ֵ��Ԫ����ͳ��
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
	
	//��������

}