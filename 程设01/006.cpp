#include<iostream>
using namespace std;
struct fx {
	double x;
	double y;
};
int main()
{
	std::cout << "输入数据个数";
	int n;
	cin >> n;
	fx* hanshu;
	hanshu = new fx[n];
	std::cout << "输入步长";
	double step;
	cin >> step;
	std::cout << "输入x";
	for (int i = 0; i < n; i++)
	{
		cin >> hanshu[i].x;
	}
	std::cout << "输入函数值";
	for (int j = 0; j < n; j++)
	{
		cin >> hanshu[j].y;
	}
	int m;
	std::cout << "输入目标自变量左一x序号（0开始）";
	cin >> m;
	double** chafen;
	chafen = new double*[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		chafen[i] = new double[n - 1];
	}
	for (int i = 0; i < n - 1; i++)
	{
		chafen[0][i] = hanshu[i + 1].y - hanshu[i].y;
	}
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			chafen[i][j] = chafen[i - 1][j]-chafen[i-1][j-1];
		}
	}
	double xx;
	std::cout << "输入目标自变量";
	cin>>xx;
	double t,cha; 
	cha = (xx - hanshu[m].x)/step;
	double jinsizhi;
	jinsizhi = hanshu[m].y;
	int b = 1;
	t = cha;
	for (int i = 0; i < n - m - 1; i++)
	{
		
		jinsizhi = jinsizhi + t*chafen[i][i+m] / (double)b;
		b = b*(i + 2);
		t = t*(cha - i - 1);
	}
	std::cout << jinsizhi<<endl;
	return 0;
}