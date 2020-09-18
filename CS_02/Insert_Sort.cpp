#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

int main()
{
	int QueueSrc[1000];
	int numbers = 0;
	printf("输入元素数量：");
	scanf("%d",&numbers);

	int temp;

	for (int i = 0; i < numbers; i++)
	{
		scanf("%d", QueueSrc + i);
	}

	for (int i = 1; i < numbers; i++)
	{
		temp = QueueSrc[i];
		int j = i - 1;
		while ((j >= 0) & (QueueSrc[j] > temp))
		{
			QueueSrc[j + 1] = QueueSrc[j];
			j = j - 1;
		}
		QueueSrc[j + 1] = temp;
	}

	for (int i = 0; i < numbers; i++)
	{
		printf("%d ", QueueSrc[i]);
	}

	return 0;
}