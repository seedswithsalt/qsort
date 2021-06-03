#include "utils.h"

void swap(void* a, char* b, size_t size)
{
	void* tmp = malloc(size);
	memcpy(tmp, a, size);
	memcpy(a, b, size);
	memcpy(b, tmp, size);

	free(tmp);
}

size_t partition(char* arr, size_t s, size_t n, int (*cmpFunc)(void const*, void const*))
{
	size_t i = 0;
	for (size_t j = 0; j < n; j++) {
		if ((*cmpFunc)(arr + j * s, arr) <= 0)
			swap(arr + s * i++, arr + j * s, s);
	}
	swap(arr, arr + (i - 1) * s, s);
	return i - 1;
}

unsigned long long qSort(void* a, size_t n, size_t sizeOfElements, int (*cmpFunc)(void const*, void const*), enum qsortType qsortType)
{
	if (n <= 1)
		return 0;
	char* arr = (char*)a;
	size_t i;
	unsigned long long comps = 0;
	switch (qsortType)
	{
	case FIRST:
		i = 0;
		break;
	case LAST:
		i = n - 1;
		break;
	case RANDOM:
		i = rand() % n;
		break;
	case MED_FROM_3:
		if ((cmpFunc(arr, arr + sizeOfElements * n / 2) > 0) != (cmpFunc(arr, arr + sizeOfElements * (n - 1)) > 0)) {
			i = 0;
			comps = 2;
		}
		else {
			comps = 4;
			if ((cmpFunc(arr + sizeOfElements * n / 2, arr) > 0) != (cmpFunc(arr + sizeOfElements * n / 2, arr + sizeOfElements * (n - 1)) > 0))
				i = n / 2;
			else
				i = n - 1;
		}
		break;
	default:
		exit(2);
		break;
	}
	swap(arr + i * sizeOfElements, arr, sizeOfElements);
	size_t j = partition(arr, sizeOfElements, n, cmpFunc);
	comps += n;
	comps += qSort(arr, j, sizeOfElements, cmpFunc, qsortType);
	comps += qSort(arr + (j + 1) * sizeOfElements, n - j - 1, sizeOfElements, cmpFunc, qsortType);
	return comps;
}

int compareInt(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void createRandomArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand();
}