#include<iostream>
#include<vector>
#include<functional>

//�麯��������ѧϰ
class shape
{
	public:
		void setHight(double H)
		{	
		//this->h = H; //����д��֪���Բ���
			hight = H;
		}

		void setWidth(double W)
		{	
		//this->w = W;
			width = W;
		}

		virtual double CompS() = 0; //���������麯��

	protected:
		double hight;	

		double width;

}; //������

class triangle :public shape
{
	public:double CompS()	   //������������㷽����д
	{	
		double S = hight * width / 2;
		return S;
	}

}; //����̳�1��������

class rectangle :public shape
{
	public:double CompS()	
	{	 		
		double S = hight * width;		//�������������д
		return S;	
	}

}; //����̳�2������

//����ģ��ѧϰ ��ͬ�������͵ļӷ�����
template<typename T> void Swap_CGYT(T a, T b,T &c) 
{	
	c = a + b;
	//std::cout << c << std::endl;
}
/*
������������ԣ���������ַ�򴫲���ֵ��ȥЧ����ͬ���������������ǲ���ֵ���ǲ�����ַ��
������Ӧ�û����·����ڴ����ڴ洢����ֵ����Ӱ��main�����еı���ֵ��
��û�з���ֵ������£��������κζԴ���������еĲ���������Ӱ��main�����е�ԭʼ������
��ˣ��������Ҫôʹ�ô����ַ��Ҫôʹ�÷���ֵ����������������޷��޸�main�����еı���ֵ��
*/

//ģ����ѧϰ
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

//��ͨ��̳�ģ����
class Tem_inher_cgyt :public Cgyt_Class_of_multiple<double> 
{
	public:
		void div(double &c)
		{
			c = A / B;
		};
};

// std::fuction���� ���÷�����װ�� 20200223
int add(int a, int b, int c)
{
	int d = a + b + c;
	return d;
}

int main()
{
	//�麯��ʵ��ѧϰ
	rectangle RecA;	
	RecA.setHight(2.3);
	RecA.setWidth(4.6);
	double S_RecA = RecA.CompS();
	std::cout << S_RecA << std::endl;

	//����ģ��ʵ��ѧϰ
	double A, B, C;
	A = 1.2;
	B = 2.3; C = 0;
	Swap_CGYT(A, B, C);
	std::cout << C << std::endl;
	int a, b, c;
	a = 1; b = 2; c = 0;
	Swap_CGYT(a, b, c);
	std::cout << c << std::endl;

	//��ģ��ʵ��ѧϰ
	Cgyt_Class_of_multiple<int> X;
	int i, j, k;
	i = 2; j = 5;
	X.Set_num(i,j);
	X.mul(k);
	std::cout << k << std::endl;

	//����ͨ�����ĵ��� 20200223
	std::function<int(int, int, int)> f = add; //function����
	int result = f(2, 3, 4);
	std::cout << result << std::endl;

	return 0;
}