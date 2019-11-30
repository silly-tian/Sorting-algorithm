#include "stdio.h"
#include "stdlib.h"

void sink(int data[], int index, int n);
void buildHeap(int data[], int n);
void sort(int data[], int n);

void sort(int data[], int n)
{
	buildHeap(data, n);
	for (int i = n - 1; i > 0; i--)
	{
		int z = data[i];
		data[i] = data[0];
		data[0] = z;
		n--;
		sink(data, 0, n);
	}
}

void sink(int data[], int index, int n)
{
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int present = index;
	if (leftChild < n && data[leftChild] > data[present])
	{
		present = leftChild;
	}
	if (rightChild < n && data[rightChild] > data[present])
	{
		present = rightChild;
	}
	if (present != index)
	{
		int z = data[present];
		data[present] = data[index];
		data[index] = z;
		sink(data, present, n);
	}
}

void buildHeap(int data[], int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		sink(data, i, n);
	}
}

int main()
{
	int data[] = { 8, 2, 5, 0, 7, 4, 6, 1, 3 };
	int n = 9;
	int i;
	printf("原数组为: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	sort(data, n);
	printf("排序后的数组为: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}