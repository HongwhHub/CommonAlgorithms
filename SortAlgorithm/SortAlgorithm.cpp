// SortAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//交换
template <class T>
void swap(T &a, T &b);
template <class T>
void swap(T *a, int i, int j);

//冒泡排序
template <class T>
void BubbleSort(T *a, int arraySize);

//选择排序
template <class T>
void SelectSort(T *a, int arraySize);

//插入排序
template <class T>
void InsertionSort(T *a, int arraySize);

int main()
{
	int a[5] = { 2,4,1,3,9 };
	//BubbleSort(a, 5);
	SelectSort(a, 5);
    return 0;
}

template<class T>
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void swap(T * a, int i, int j)
{
	T tmp = *(a + i);
	*(a + i) = *(a + j);
	*(a + j) = tmp;
}

template<class T>
void BubbleSort(T * a, int arraySize)
{
	if (a == nullptr || arraySize == 2)
		return;
	for (int end = arraySize - 1; end > 0; end--)
		for (int i = 0; i < end; i++)
			if (a[i] < a[i + 1])
				swap(a[i], a[i + 1]);
}

template<class T>
void SelectSort(T * a, int arraySize)
{
	if (a == nullptr || arraySize == 2)
		return;
	for (int i = 0; i < arraySize - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < arraySize; j++)
			maxIndex = a[j] > a[maxIndex] ? j : maxIndex;
		swap(a, i, maxIndex);
	}
}

template<class T>
void InsertionSort(T * a, int arraySize)
{
	if (a == nullptr || arraySize == 2)
		return;
	for (int i = 1; i < arraySize; i++)
		for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			swap(a[j], a[j + 1]);
}
