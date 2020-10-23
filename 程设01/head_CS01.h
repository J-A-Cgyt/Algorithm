#pragma once

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#ifndef Over_Write_off  //用于重载操作符的相关类与函数声明

class box
{
private:
	float length;  //成员函数应该是可以随便调的
	float breadth;
	float height;
public:
	box(float L, float B, float H);

	float Volume();

	void  setParam(float L, float B, float H);

	//重载运算符 '+'
	box operator+ (const box& b); //此处为类的成员函数所以第一个被加参数写为this

	//重载运算符 = 
	void operator=(const box&a);

	void operator=(const float & x);

};

#endif // !Over_Write_off

