#include<iostream>

using namespace std;

int* myjia(int n, int a[], int m, int b[])
{
	int* c;
	if (n > m)
	{
		c = new int[n];
	}
	else
	{
		c = new int[m];
	}
	for (int i = 0; i < m && i < n; i++)
	{
		c[i] = a[i] + b[i];
	}
	if (n>m)
	{
		for (int i = m; i < n; i++)
		{
			c[i] = a[i];
		}
	}
	else
	{
		for (int i = n; i < m; i++)
		{
			c[i] = b[i];
		}
	}
	return c;
}

int* myjian(int n, int a[], int m, int b[])
{
	int* d;
	if (n > m)
	{
		d = new int[n];
	}
	else
	{
		d = new int[m];
	}
	for (int i = 0; i < m && i < n; i++)
	{
		d[i] = a[i] - b[i];
	}
	if (n>m)
	{
		for (int i = m; i < n; i++)
		{
			d[i] = a[i];
		}
	}
	else
	{
		for (int i = n; i < m; i++)
		{
			d[i] = -b[i];
		}
	}
	return d;
}

int* mycheng(int n, int a[], int m, int b[])
{
	int* e;
	e = new int[m + n - 1];
	for (int i = 0; i < m + n - 1; i++)
	{
		e[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			e[i + j] = e[i + j] + a[i] * b[j];
		}
	}
	return e;
}

double* mychu(int n, int a[], int m, int b[])
{
	double* f;
	double* aa;
	aa = new double[n];
	for (int i = 0; i < n; i++)
	{
		aa[i] = (double)a[i];
	}	
	double* bb;
		f = new double[n - m + 1];
	    bb = new double[m];
	for (;;)
	{
		f[n - m] = aa[n - 1] / (double)b[m - 1];
	
		for (int i = 0; i < n; i++)
		{
			bb[i] = f[n - m] * (double)b[i];
		}
		for (int i = n - 1; i > n - m - 1; i--)
		{
			aa[i] = aa[i] - bb[i + m - n];
		}
		if (n <= m)
		{
			break;
		}
		n = n - 1;
	}
	cout << "余式系数升幂排列：";
	for (int i = 0; i < m - 1; i++)
	{
		cout << aa[i];
	}
	cout << endl;
	delete aa, bb;
	return f;
}

int main()
{
	int n, m;
	cin >> n;
	int* a;
	int* b;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	b = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	/*int* c;
	c = myjia(n, a, m, b);
	for (int i = 0; i < m || i < n; i++)
	{
	cout << c[i] << " ";
	}
	int* d;
	d = myjian(n, a, m, b);
	for (int i = 0; i < m || i < n; i++)
	{
	cout << d[i] << " ";
	}
	int* e;
	e = mycheng(n, a, m, b);
	for (int i = 0; i < m + n - 1 ; i++)
	{
	cout << e[i] << " ";
	}*/
	double* f;
	f = mychu(n, a, m, b);
	cout << "结果多项式系数升幂排列:";
	for (int i = 0; i < n - m + 1; i++)
	{
		cout << f[i] << " ";
	}
	delete a, b;
	delete f;
	return 0;
}