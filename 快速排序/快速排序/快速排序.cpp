#include "stdio.h"
#include "stdlib.h"

void sort(int data[], int startIndex, int endIndex);
int partition(int data[], int startIndex, int endIndex);

void sort(int data[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}
	int pivotIndex = partition(data, startIndex, endIndex);
	sort(data, startIndex, pivotIndex - 1);
	sort(data, pivotIndex + 1, endIndex);
}

int partition(int data[], int startIndex, int endIndex)
{
	int z;
	int flag = 1;
	int left = startIndex;
	int right = endIndex - 1;
	int pivot = data[endIndex];
	if (left == right)
	{
		flag = 0;
	}
	while (flag)
	{
		while (data[left] <= pivot && flag)
		{
			left++;
			if (left == right)
			{
				flag = 0;
				break;
			}
		}
		while (data[right] >= pivot && flag)
		{
			right--;
			if (left == right)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			z = data[left];
			data[left] = data[right];
			data[right] = z;
		}
	}
	z = data[endIndex];
	data[endIndex] = data[right];
	data[right] = z;
	return right;
}

int main()
{
	int i;
	int data[] = { 8, 2, 5, 0, 7, 4, 6, 1, 3 };
	printf("原数组为:");
	for (i = 0; i < 9; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	sort(data, 0, 8);
	printf("排序后的数组为:");
	for (i = 0; i < 9; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}