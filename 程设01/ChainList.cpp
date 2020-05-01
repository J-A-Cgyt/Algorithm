#include<iostream>
#include<cstdlib>

using namespace std;
typedef struct NODE 列表元;
typedef struct NODE {
	int Data;
	列表元* Next;
}列表元;

typedef 列表元* 头;

int Getlistlength(头 head)
{
	int k = 0;
	for (;;)
	{
		if (head->Next != NULL)
		{
			k = k + 1;
			head = head->Next;
		}
		else
		{
			return k;
		}
	}
}

void DestoryList(头 head)
{
	头 临时;
	while (head->Next)
	{
		临时 = head;
		head = head->Next;
		delete(临时);
	}
}

int GetElement(头 head, int pos, int* DP)
{
	头 Head = head;
	if (Getlistlength(Head)<pos)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < pos; ++i)
		{
			head = head->Next;
		}
		*DP = head->Data;
	}
	return 1;
}

int FindElement(头 head, int Data)
{
	头 Head = head;
	int length = Getlistlength(Head);
	for (int i = 0; i < length; i++)
	{
		
		if (head->Data == Data)
		{
			return 1;
		}
		head = head->Next;
	}
	return -1;
}

头 InsertElement(int Data, 列表元* prime)
{
	列表元* Insert;
	列表元* temp;
	Insert = new 列表元;
	Insert->Data = Data;
	temp = prime->Next;
	prime->Next = Insert;
	Insert->Next = temp;
	return Insert;
}

int DeleteElement(头 prime)
{
	头 temp;
	temp=prime->Next->Next;
	delete prime->Next;
	prime->Next = temp;
	return 1;
}

int main()
{
	cout << "aaa" << endl;
	return 0;

}