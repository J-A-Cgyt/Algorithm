#include<iostream>
using namespace std;

struct shuju {
	int b;
	int c1;
	int c2;
};

int bijiao2(int a, int b,int c)
{
	int x[4];
	int y[4];
	int z; z = 0;
	for (int i = 0; a >= 1; i++)
	{
		x[i] = a % 10;
		a = a / 10;
		y[i] = b % 10;
		b = b / 10;
	}
	for (int i = 0; i < 4; i++)
	{
		if (x[i] == y[i])
		{
			z = z + 1;
		}
	}
	if (z == c)
	{
		return 1;
	}
	return 0;
}

int bijiao1(int a, int b, int c)
{
	int x[4];
	int y[4];
	int z; z = 0;
	for (int i = 0; a >= 1; i++)
	{
		x[i] = a % 10;
		a = a / 10;
		y[i] = b % 10;
		b = b / 10;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (x[i] == y[j])
			{
				z = z + 1;
				y[j] = -1;
				break;
			}
		}
	}
	if (z == c)
	{
		return 1;
	}
	return 0;
}

/*int main()
{
	int a, b, c1,c2;
	a = 3585;
	b = 8555;
	c1 = 3;c2=2;
	cout<<bijiao1(a, b, c1);
	cout<<bijiao2(a, b, c2);
}*/
int main()
{

	int x;
	cin >> x;
	for (; x != 0;)
	{
		shuju* z;
		z = new shuju[x];
		for (int i = 0; i < x; i++)
		{
			cin >> z[i].b >> z[i].c1 >> z[i].c2;
		}
		int k[9000]; k[0] = 0; k[1] = 0;
		int j = 0;
		for (int a = 1000; a < 10000; a++)
		{
			int y = 1;

			for (int i = 0; i < x; i++)
			{
				y = y * bijiao1(a, z[i].b, z[i].c1)*bijiao2(a, z[i].b, z[i].c2);
			}
			if (y == 1)
			{
				k[j] = a;
				j = j + 1;
			}
		}
		if (k[0] != 0 && k[1] == 0)
		{
			cout << k[0]<<endl;
		}
		else
		{
			cout << "Not sure"<<endl;
		}
		cin >> x;
	}
}