// part7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef int(*CMP)(const void*, const void*);

int arr[] = { 9,6,3,6,12,4,1,23,31,2,0 };

int intCMP(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

char* get_pointer(void* base, size_t index, size_t size)
{
	char* b = static_cast<char*>(base);
	return (b + index*size);
}

void in_qsort(void* base, size_t n, size_t size, CMP cmp, int l, int r)
{
	std::cout << "in_qsort " << l << " " << r << "\n";
	char* b = static_cast<char*>(base);
	int i = l;
	int j = r;
	char* q = b + ((l + r) / 2) * size;
	do
	{
		while (cmp(b + i*size, q) < 0)
			i++;
		while (cmp(q, b + j*size) < 0)
			j--;
		if (i <= j)
		{
			char* s1 = b + i*size;
			char* s2 = b + j*size;
			for (int k = 0; k < size; k++)
			{
				char buf = s1[k];
				s1[k] = s2[k];
				s2[k] = buf;
			}
			i++;
			j--;
		}
	} while (i <= j);
	//std::cout << *bufl << " " << *j << " " << (bufl < j) << "\n";
	if (l < j) in_qsort(base, n, size, cmp, l, j);
	if (i < r) in_qsort(base, n, size, cmp, i, r);
}

void qsort(void* base, size_t n, size_t size, CMP cmp)
{
	in_qsort(base, n, size, cmp, 0, n-1);
}



int main()
{
	for (size_t i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\nSorting...\n" << sizeof(int);
	qsort(arr, 11, 4, intCMP);
	for (size_t i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
	system("Pause");
    return 0;
}

