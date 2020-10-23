//��Դ�ļ�����дһЩ�������صģ����������õĶ��� ��Ҫ�ǲ���������
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

//��������� '+'
box box::operator+ (const box& b) //�˴�Ϊ��ĳ�Ա�������Ե�һ�����Ӳ���дΪthis������Ҳ����ʥ��this->
{
	box c(0,0,0);
	c.breadth = this->breadth + b.breadth;
	c.height = this->height + b.height;
	c.length = this->length + b.length;
	return c;
};

//��������� = 
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
//ע�⣬������ԣ���ʵ�Ѿ�����һ��Ĭ�ϵ� ���Ʋ�������=��������ǿ������г�Ա������ֵ 
//����Ա��������ָ�����������������е�������������Ĳ��������ٸ�ֵ��ɾ��ʵ��ʱ��ɶ�ͬһƬ�ڴ�������ж���ɾ�����𱨴�
//��ʱ�������صĸ�ֵ������"="�������

/*
��������������Ҫ��ʽ���ṩ��ֵ��������غ��������Զ��帳ֵ��������غ�������
�÷���A���͵�ֵΪ��A�Ķ���ֵʱ����Ȼ��������������ǿ��Բ��ṩ��Ӧ�ĸ�ֵ��������غ�������ֻ�ṩ��Ӧ�Ĺ��캯��������ĺ��ʾ������2�����ڶ������ظ�ֵ��������������
������A���͵�ֵΪ��A�Ķ���ֵ������A�����ݳ�Ա�к���ָ�������£�������ʽ�ṩ��ֵ��������غ�������ʾ������1����
��Դ��ַ��https://blog.csdn.net/liitdar/article/details/80656156
*/