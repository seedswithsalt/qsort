#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"

void test(int* a, int* b, int n, enum qsortType pivot)
{
	unsigned long long comp = 0;
	for (int i = 0; i < 15; i++)
	{
		createRandomArr(a, n);
		memcpy(b, a, n * sizeof(int));
		comp += qSort(a, n, sizeof(int), compareInt, pivot);
		qsort(b, n, sizeof(int), compareInt);
	}
	printf("\tArray sorted correctly 15 times, on average %llu comparisons\n", comp / 10);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n1 = 10, n2 = 1000;
	int* a = (int*)calloc(n2, sizeof(int));
	int* b = (int*)calloc(n2, sizeof(int));
	if (!a || !b)
		exit(1);
	srand(time(NULL));
	char outs[4][40] = { "*----Pivot element - first:\n" , "*----Pivot element - last:\n",
	"*----Pivot element - random:\n", "*----Pivot element - median of 3:\n" };
	for (int i = 0; i < 4; i++)
	{
		printf(outs[i]);
		printf("Array of %d elements:\n", n1);
		printf("\t----Random array:\n");
		test(a, b, n1, i);
		printf("Array of %d elements:\n", n2);
			test(a, b, n2, i);
	}
	free(a);
	free(b);
	return 0;
}