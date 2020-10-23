#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//��Դ�ļ�����ɢ�б���ط�����ʵ�� �㷨����chp11

struct Data_DAT
{
	unsigned char Key;  //���ڼ������ݵĹؼ��� ����С������޷����˹�����������û��
	
	double ValueD;
	float ValueF;
	int ValueI;
};

Data_DAT* Direct_Address_Table[100]; //ֱ��Ѱַ�� �ɼ���Ϊ���ֱ��Ѱַ���˱�����100�����ݣ�0-99���Ǵ�ֱ��Ѱַ���ȫ�ؼ����� �ٶ��ָ�������� from 11.1
//�ϱ���ؼ�����������Ӧ��ֱ�Ӿ��ǵ�ַ ���º������ٴ˵�ַ���н��в�������Ϊȫ�ֱ���������ж����������д�ĸ���һЩ��

void INSERT_DAT(Data_DAT &x)
{
	Direct_Address_Table[x.Key] = &x;
}

void INSERT_OpenAdd(Data_DAT &x)  //����Ѱַ���Ĳ��뺯����ɢ�к�������ʹ������̽�顢����̽���˫��ɢ�� ˫��ɢ�л���Ҫ�����͸�����ɢ�к���
{
	int i = 0;
	int h = -1;
	while (1) 
	{
		int h = (x.Key + i + 14) % 100;  //����Ѱַ ɢ�к�������ñ�֤Ψһ�ԣ��˺���Ϊ����̽�飬û���Ҿ�ȻҲ�ܲµ�����������
		if (Direct_Address_Table[h] == nullptr)
		{
			Direct_Address_Table[h] = &x;
			return;
		}
		else
		{
			i = i + 1;
		}
		if (i == 100)
		{
			printf("Ѱַ�����������");
			return;
		}
	}
}

Data_DAT SEARCH_DAT(unsigned char key)
{
	return *Direct_Address_Table[key];
}

Data_DAT SEARCH_OpenAdd(unsigned char key)
{
	int i = 0;
	int h = -1;
	Data_DAT Empty;
	Empty.Key = -1;
	while (1)
	{
		h = (key + i + 14) % 100; 
		if (Direct_Address_Table[h]== nullptr)
		{
			printf("û�Ҽ�");
			return Empty;
		}
		else if (Direct_Address_Table[h]->Key == key)
		{
			return *Direct_Address_Table[h];
		}
		else
		{
			i = i + 1;
		}
		if (i == 100)
		{
			printf("û�Ҽ�,���Һ�������");
			return Empty;
		}
	}
}

int Full_Hash_Func(int &a, int &b, int &key) //ȫ��ɢ�к����������趨a,bֵ��p,mָ��������mΪ��������������
{
	int p = 17; //p��Ҫʱ����
	int m = 6;

	int h;
	h = ((a*key + b) % p) % m;
	return h;
}

int main()
{
	Data_DAT a, b, c, d, e, f;

	a.Key = 0; c.Key = 54; e.Key = 65;
	b.Key = 3; d.Key = 43; f.Key = 6;

	INSERT_DAT(a); INSERT_DAT(b); INSERT_DAT(c);
	INSERT_DAT(d); INSERT_DAT(e); INSERT_DAT(f);

	int aa = 3, bb = 4, key = 8;  //ȫ��ɢ�к������㿴
	int h_test = Full_Hash_Func(aa, bb, key);

	Data_DAT INS_OpenAdd;
	INS_OpenAdd.Key = 29;  //����Ѱַ���Ĳ�������
	INSERT_OpenAdd(INS_OpenAdd);

	Data_DAT RECIVE;
	key = 28;
	RECIVE = SEARCH_OpenAdd(key);

	return 0;
}