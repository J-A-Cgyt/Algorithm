#include<iostream>
using namespace std;

int main()
{
	int i = 6;
	double x[6], y[6];
	x[0] = 0.4;     x[1] = 0.55;    x[2] = 0.65;    x[3] = 0.8;     x[4] = 0.9;     x[5] = 1.05;
	y[0] = 0.41075; y[1] = 0.57815; y[2] = 0.69675; y[3] = 0.88811; y[4] = 1.02652; y[5] = 1.25386;

	double X = 0.596;
	double Y[6];
	double YY = 0;
	for (int k = 0; k < 6; k++)
	{
		Y[k] = 1;
		for (int t = 0; t < 6; t++)
		{
			if (k == t)
			{
				continue;
			}
			Y[k] = (X - x[t]) / (x[k] - x[t]) * Y[k];
		}
		Y[k] = Y[k] * y[k];
		cout << Y[k]<<endl;
		YY = YY + Y[k];
	}
	cout << YY;

	return 0;
}