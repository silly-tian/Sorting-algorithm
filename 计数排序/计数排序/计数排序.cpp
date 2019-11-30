#include "stdio.h"
#include "stdlib.h"

void sort(int data[], int n);

void sort(int data[], int n)
{
	int i;
	int j;
	int max = data[0];
	for (i = 0; i < n; i++)
	{
		if (max < data[i])
		{
			max = data[i];
		}
	}
	int *data_z = (int *)malloc(sizeof(int) * (max + 1) );
	for (i = 0; i < max + 1; i++)
	{
		data_z[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		data_z[data[i]]++;
	}
	j = 0;
	i = 0;
	while (i < max + 1)
	{
		if (data_z[i] == 0)
		{
			i++;
			continue;
		}
		else
		{
			data[j] = i;
			j++;
			data_z[i]--;
		}
	}
}

int main()
{
	int data[] = { 3, 5, 8, 2, 5, 4 };
	int n = 6;
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