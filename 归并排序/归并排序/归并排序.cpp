#include "stdio.h"
#include "stdlib.h"

void discerption(int data[], int data_z[], int startIndex, int endIndex);
void sort(int data[]);
void merge(int data[], int data_z[], int startIndex, int middleIndex, int endIndex);

void sort(int data[])
{
	int *data_z = (int *)malloc(sizeof(int) * 9);
	discerption(data, data_z, 0, 9 - 1);
}

void discerption(int data[], int data_z[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}
	int middleIndex = startIndex + (endIndex - startIndex) / 2;
	discerption(data, data_z, startIndex, middleIndex);
	discerption(data, data_z, middleIndex + 1, endIndex);
	merge(data, data_z, startIndex, middleIndex, endIndex);
}

void merge(int data[], int data_z[], int startIndex, int middleIndex, int endIndex)
{
	for (int i = startIndex; i < endIndex + 1; i++)
	{
		data_z[i] = data[i];
	}
	int left = startIndex;
	int right = middleIndex + 1;
	for (int i = startIndex; i < endIndex + 1; i++)
	{
		if (left > middleIndex)
		{
			data[i] = data_z[right++];
		}
		else if (right > endIndex)
		{
			data[i] = data_z[left++];
		}
		else if (data_z[left] > data_z[right])
		{
			data[i] = data_z[right++];
		}
		else
		{
			data[i] = data_z[left++];
		}
	}
}

int main()
{
	int i;
	int data[] = { 8, 2, 5, 0, 7, 4, 6, 1, 3 };
	printf("原数组为: ");
	for (i = 0; i < 9; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	sort(data);
	printf("排序好的数组为: ");
	for (i = 0; i < 9; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}