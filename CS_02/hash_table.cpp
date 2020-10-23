#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//此源文件用于散列表相关方法的实现 算法导论chp11

struct Data_DAT
{
	unsigned char Key;  //用于检索数据的关键字 啊不小心设成无符号了哈哈哈哈负数没用
	
	double ValueD;
	float ValueF;
	int ValueI;
};

Data_DAT* Direct_Address_Table[100]; //直接寻址表 可见，为完成直接寻址，此表最多存100个数据，0-99就是此直接寻址表的全关键字域 再多就指不过来了 from 11.1
//上表里关键字与索引对应，直接就是地址 以下函数均再此地址表中进行操作，设为全局变量，如果有多个，则需再写的复杂一些。

void INSERT_DAT(Data_DAT &x)
{
	Direct_Address_Table[x.Key] = &x;
}

void INSERT_OpenAdd(Data_DAT &x)  //开放寻址法的插入函数，散列函数可以使用线性探查、二次探查或双重散列 双重散列会需要两个和辅助的散列函数
{
	int i = 0;
	int h = -1;
	while (1) 
	{
		int h = (x.Key + i + 14) % 100;  //开放寻址 散列函数，最好保证唯一性，此函数为线性探查，没看我居然也能猜到哈哈哈哈哈
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
			printf("寻址出错，队列溢出");
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
			printf("没找见");
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
			printf("没找见,而且后面满了");
			return Empty;
		}
	}
}

int Full_Hash_Func(int &a, int &b, int &key) //全域散列函数，自行设定a,b值，p,m指定，其中m为索引表的最大容量
{
	int p = 17; //p需要时素数
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

	int aa = 3, bb = 4, key = 8;  //全域散列函数算算看
	int h_test = Full_Hash_Func(aa, bb, key);

	Data_DAT INS_OpenAdd;
	INS_OpenAdd.Key = 29;  //开放寻址法的测试数据
	INSERT_OpenAdd(INS_OpenAdd);

	Data_DAT RECIVE;
	key = 28;
	RECIVE = SEARCH_OpenAdd(key);

	return 0;
}