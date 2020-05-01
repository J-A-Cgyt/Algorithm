#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct DATA
{
	char name[20];
	char number[20];
}Data; /*数据类型定义*/

typedef struct LIST
{
	Data* Datapoint;
	int Max;
	int Length;
}List;  /*线性表类型定义*/

List* CreateList(int MAX)
{
	List* ListPoint;
	ListPoint = (List*)malloc(sizeof(List));
	ListPoint->Datapoint = (Data*)malloc(MAX*sizeof(Data));
	ListPoint->Max = MAX;
	ListPoint->Length = 0;
	return ListPoint;
}    /*线性表创建，返回指针*/

int AddData(Data xin, List* ListPoint)
{
	if (ListPoint->Length < ListPoint->Max)
	{
		ListPoint->Datapoint[ListPoint->Length] = xin;
		ListPoint->Length = ListPoint->Length + 1;
		return 1;
	}
	else
	{
		return -1;
	}

} /*添加数据*/

int InsetData(Data xin, int Location, List* ListPoint)
{
	if (ListPoint->Length < ListPoint->Max)
	{
		for (int i = ListPoint->Length - 1; i > Location - 1; i--)
		{
			ListPoint->Datapoint[i + 1] = ListPoint->Datapoint[i];
		}
		ListPoint->Datapoint[Location - 1] = xin;
		ListPoint->Length = ListPoint->Length + 1;
		return 1;
	}
	else
	{
		return -1;
	}
}  /*数据插入*/

int DeleteData(int Location, List* ListPoint)
{
	if (Location < ListPoint->Length&&Location>0)
	{
		for (int i = Location; i < ListPoint->Length; i++)
		{
			ListPoint->Datapoint[i - 1] = ListPoint->Datapoint[i];
		}
		ListPoint->Length = ListPoint->Length - 1;
		return 1;
	}
	else
	{
		return -1;
	}
} /*删除数据*/

int CleanList(List* ListPoint)
{
	ListPoint->Length = 0;
	return 1;
}  /*清空表*/

int DestoryList(List* ListPoint)
{
	free(ListPoint->Datapoint);
	free(ListPoint);
	return 1;
} /*销毁表*/

void Showlist(List* ListPoint)
{
	int n = 0;
	for (; n < ListPoint->Length; n++)
	{
		printf("%s\n", ListPoint->Datapoint[n].name);
		printf("%s\n", ListPoint->Datapoint[n].number);
	}
} /*显示表中数据*/

int GetLength(List* ListPoint)
{
	int a;
	a = ListPoint->Length;
	return a;
} /*获取表长度*/

int main()
{
	int n;
	scanf("%d", &n);
	List* L;
	L = CreateList(n);
	int a, b, c, d, e, f, g, h;
	f = 2;
	Data D1, D2, D3, D4;
	strcpy(D1.name, "zhangsan");
	strcpy(D1.number, "1111111");
	strcpy(D2.name, "lisi");
	strcpy(D2.number, "2222222");
	strcpy(D3.name, "wangwu");
	strcpy(D3.number, "3333333");
	strcpy(D4.name, "zhaoliu");
	strcpy(D4.number, "4444444");
	b = AddData(D1, L);
	printf("%d\n", b);
	c = AddData(D2, L);
	printf("%d\n", c);
	a = AddData(D3, L);
	printf("%d\n", a);
	Showlist(L);
	e = DeleteData(f, L);
	printf("%d\n", e);
	Showlist(L);
	g = InsetData(D4, f, L);
	h = GetLength(L);
	printf("%d\n%d\n", g, h);
	Showlist(L);
	d = DestoryList(L);
	printf("%d\n", d);
	return 0;
}