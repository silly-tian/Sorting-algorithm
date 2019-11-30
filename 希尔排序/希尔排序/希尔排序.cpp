#include "stdio.h"
#include "stdlib.h"

int main()
{
	int data[] = { 61, 109, 149, 111, 34, 2, 24, 119, 122, 125, 27, 145 };
	int n = 12;
	int i = 0;
	int gap = n;
	while (gap != 1)
	{
		i = 0;
		gap = gap / 2;
		while (i < n - gap)
		{
			int j = i;
			while (data[j] > data[j + gap] && j > -1)
			{
				int z = data[j];
				data[j] = data[j + gap];
				data[j + gap] = z;
				j -= gap;
			}
			i++;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}

	system("pause");
	return 0;
}