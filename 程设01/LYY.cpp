#include <iostream>
#include<vector>

using namespace std;

void meger(vector<double> ori, int left, int mid, int right) 
{
	vector<double> res(ori.size());
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) 
	{
		//？？？res[k++] = ori[i++] < ori[j++] ? ori[i++] : ori[j++];
		if (ori[i] < ori[j])
		{
			res[k] = ori[i];
			i++;
			k++;
		}
		else
		{
			res[k] = ori[j];
			j++;
			k++;
		}
	}
	while (i <= mid) 
	{
		res[k++] = ori[i++];
	}
	while (j <= right) 
	{
		res[k++] = ori[j++];
	}
	for (int m = 0; m < res.size(); m++) 
	{
		ori[m] = res[m];
	}

	//阿苗添加的debug代码
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;
}

void sort(vector<double> ori, int left, int right) {
	if (left < right) 
	{
		int mid = (left + right) / 2;
		sort(ori, left, mid);
		sort(ori, mid + 1, right);
		meger(ori, left, mid, right);
	}
}

void Megersort(vector<double> &array) 
{
	sort(array, 0, array.size() - 1);
}

int main()
{
	vector<double> a;
	cout << "请输入要比较的数组：（请以空格开始输入）\n";
	int num;
	//数组输入
	while (getchar() != '\n')
	{
		cin >> num;
		a.push_back(num);
	}
	//显示输入数组
	cout << "需要排序的数组为：\n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	Megersort(a);

	cout << "排序完为：\n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
}