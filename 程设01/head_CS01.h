#pragma once

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#ifndef Over_Write_off  //�������ز�������������뺯������

class box
{
private:
	float length;  //��Ա����Ӧ���ǿ���������
	float breadth;
	float height;
public:
	box(float L, float B, float H);

	float Volume();

	void  setParam(float L, float B, float H);

	//��������� '+'
	box operator+ (const box& b); //�˴�Ϊ��ĳ�Ա�������Ե�һ�����Ӳ���дΪthis

	//��������� = 
	void operator=(const box&a);

	void operator=(const float & x);

};

#endif // !Over_Write_off

