#include <iostream>
#include <WinSock2.h>

using namespace std;
int main()
{
	//socket();

	int n, m;
	int i, j;
	int max;
	int M[21][21];
	int MAX[21];
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		max = M[i][0];
		for (j = 0; j < m; j++)
		{
			cin>>M[i][j];
			if (max < M[i][j])
			{
				max = M[i][j];
				//cout << "maxL=" << max << endl;
			}
		}
		//cout << "max" << max << " ";
		MAX[i] = max;
	}
	for (i = 0; i < n; i++)
	{
		cout << MAX[i] << endl;
	}

	return 0;
}

