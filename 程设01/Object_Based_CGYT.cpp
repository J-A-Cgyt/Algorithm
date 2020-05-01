#include<iostream>
#include<vector>
#include<functional>

//虚函数、虚类学习
class shape
{
	public:
		void setHight(double H)
		{	
		//this->h = H; //这样写不知道对不对
			hight = H;
		}

		void setWidth(double W)
		{	
		//this->w = W;
			width = W;
		}

		virtual double CompS() = 0; //面积计算的虚函数

	protected:
		double hight;	

		double width;

}; //抽象类

class triangle :public shape
{
	public:double CompS()	   //三角形面积计算方法重写
	{	
		double S = hight * width / 2;
		return S;
	}

}; //子类继承1、三角形

class rectangle :public shape
{
	public:double CompS()	
	{	 		
		double S = hight * width;		//矩形面积计算重写
		return S;	
	}

}; //子类继承2，矩形

//函数模板学习 不同数据类型的加法函数
template<typename T> void Swap_CGYT(T a, T b,T &c) 
{	
	c = a + b;
	//std::cout << c << std::endl;
}
/*
对输入参数而言，传参数地址或传参数值进去效果相同，但是如果传入的是参数值而非参数地址，
函数内应该会重新分配内存用于存储参数值而不影响main函数中的变量值，
在没有返回值的情况下，函数中任何对传入变量进行的操作都不会影响main函数中的原始变量。
因此，结果变量要么使用传入地址，要么使用返回值，仅传入参数变量无法修改main函数中的变量值。
*/

//模板类学习
template<class T> 
class Cgyt_Class_of_multiple 
{
protected:
	T A;
	T B;
public:
	T mul(T &C)
	{
		C = A * B;
		return C;
	}

	void Set_num(T &a, T &b)
	{	
		A = a;
		B = b;
	}
};

//普通类继承模板类
class Tem_inher_cgyt :public Cgyt_Class_of_multiple<double> 
{
	public:
		void div(double &c)
		{
			c = A / B;
		};
};

// std::fuction试用 调用方法封装？ 20200223
int add(int a, int b, int c)
{
	int d = a + b + c;
	return d;
}

int main()
{
	//虚函数实现学习
	rectangle RecA;	
	RecA.setHight(2.3);
	RecA.setWidth(4.6);
	double S_RecA = RecA.CompS();
	std::cout << S_RecA << std::endl;

	//函数模板实现学习
	double A, B, C;
	A = 1.2;
	B = 2.3; C = 0;
	Swap_CGYT(A, B, C);
	std::cout << C << std::endl;
	int a, b, c;
	a = 1; b = 2; c = 0;
	Swap_CGYT(a, b, c);
	std::cout << c << std::endl;

	//类模板实现学习
	Cgyt_Class_of_multiple<int> X;
	int i, j, k;
	i = 2; j = 5;
	X.Set_num(i,j);
	X.mul(k);
	std::cout << k << std::endl;

	//对普通函数的调用 20200223
	std::function<int(int, int, int)> f = add; //function调用
	int result = f(2, 3, 4);
	std::cout << result << std::endl;

	return 0;
}