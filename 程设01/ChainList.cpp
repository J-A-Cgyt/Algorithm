#include<iostream>
#include<cstdlib>

using namespace std;
typedef struct NODE �б�Ԫ;
typedef struct NODE {
	int Data;
	�б�Ԫ* Next;
}�б�Ԫ;

typedef �б�Ԫ* ͷ;

int Getlistlength(ͷ head)
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

void DestoryList(ͷ head)
{
	ͷ ��ʱ;
	while (head->Next)
	{
		��ʱ = head;
		head = head->Next;
		delete(��ʱ);
	}
}

int GetElement(ͷ head, int pos, int* DP)
{
	ͷ Head = head;
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

int FindElement(ͷ head, int Data)
{
	ͷ Head = head;
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

ͷ InsertElement(int Data, �б�Ԫ* prime)
{
	�б�Ԫ* Insert;
	�б�Ԫ* temp;
	Insert = new �б�Ԫ;
	Insert->Data = Data;
	temp = prime->Next;
	prime->Next = Insert;
	Insert->Next = temp;
	return Insert;
}

int DeleteElement(ͷ prime)
{
	ͷ temp;
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