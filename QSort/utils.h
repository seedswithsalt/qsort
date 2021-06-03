#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <crtdefs.h>


#ifndef UTILS_H
#define UTILS_H

enum qsortType {
	FIRST, LAST, RANDOM, MED_FROM_3
};

void swap(void* a, char* b, size_t size);

size_t partition(char* arr, size_t s, size_t n, int (*cmpFunc)(void const*, void const*));

unsigned long long qSort(void* a, size_t n, size_t sizeOfElem, int (*cmpFunc)(void const*, void const*), enum qsortType qsortType);

int compareInt(const void* a, const void* b);

void createRandomArr(int* arr, int n);

#endif
