#include<iostream>
using namespace std;

int isprime(int n);
int main()
{
	int x[100];
	int s = 0;
	for (; s < 100; s++)
	{
		x[s] = 0;
	}
	int m = 0;

	cin >> x[m]; 
	while (x[m] != 0)
	{

		if (isprime(x[m]) == 1 && x[m] != 0 && x[m] != 1)
		{
			cout << x[m] << " ";
		}
		m++;
		cin >> x[m];
	}
	return 0;
}

int isprime(int n)
{
	int i = 2;
	for (; i <= n - 1; i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
