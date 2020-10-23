//此源文件用于写一些关于重载的，函数重载用的多了 主要是操作符重载
#include "head_CS01.h"

box::box(float L, float B, float H)
{
	this->setParam(L, B, H);
	printf("a new box created\n");
}

float box::Volume()
{
	return length * breadth * height;
}
void  box::setParam(float L, float B, float H)
{
	this->length = L;
	this->breadth = B;
	this->height = H;
}

//重载运算符 '+'
box box::operator+ (const box& b) //此处为类的成员函数所以第一个被加参数写为this，好像也可以圣烈this->
{
	box c(0,0,0);
	c.breadth = this->breadth + b.breadth;
	c.height = this->height + b.height;
	c.length = this->length + b.length;
	return c;
};

//重载运算符 = 
void box::operator=(const box&a)
{
	this->setParam(a.length, a.breadth, a.height);
	printf("over load operator = has been used\n");
}

void box::operator=(const float &x)
{
	this->setParam(x, x, x);
	printf("second over load operator = has been used\n");
}
//注意，对类而言，其实已经会有一个默认的 复制操作符“=”其机制是拷贝所有成员变量的值 
//当成员变量存在指针类型且析构函数中调用了清除变量的操作，则再赋值后删除实例时造成对同一片内存区域进行二次删除引起报错，
//此时可用重载的赋值操作符"="解决问题

/*
针对以下情况，需要显式地提供赋值运算符重载函数（即自定义赋值运算符重载函数）：
用非类A类型的值为类A的对象赋值时（当然，这种情况下我们可以不提供相应的赋值运算符重载函数，而只提供相应的构造函数，如更改后的示例代码2）。第二个重载赋值操作符即属此类
当用类A类型的值为类A的对象赋值，且类A的数据成员中含有指针的情况下，必须显式提供赋值运算符重载函数（如示例代码1）。
来源网址：https://blog.csdn.net/liitdar/article/details/80656156
*/