// SortAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <time.h>
//对数器
template<class T>
int length(T& arr);
template <class T>
T* generateRandomArray(int size, int value);
double GetRand();
template<class T>
T * copyArray(T *arr);
template<class T>
bool asc(T a, T b);
template<class T>
bool desc(T a, T b);
template<class T>
T* rightMethod(T *arr);

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
int length(T& arr)
{
	//cout << sizeof(arr[0]) << endl;
	//cout << sizeof(arr) << endl;
	return sizeof(arr) / sizeof(arr[0]);
}

template<class T>
T * generateRandomArray(int size, int value)
{
	T arr[] = new T((T)(size + 1)*GetRand());
	arr[0] = (T)((value + 1)*GetRand()) - (T)((value)*GetRand());
	for (int i = 1; i < length(arr); i++)
	{
		arr[i] = (T)((value + 1)*GetRand()) - (T)((value)*GetRand());
	}
	return arr;
}

double GetRand()
{
	std::srand(time(NULL));
	int iRand = std::rand();
	iRand %= 10000; // 取0 ~ 9999
	return iRand / 10000.0; // 注意加".0
							// PS：保留几位小数就合适求舍，求商
}

template<class T>
T * copyArray(T *arr)
{
	T tmp[] = new T(length(arr));
	for (int i = 0; i < length(arr); i++)
		tmp[i] = arr[i];
	return tmp;
}
template<class T>
bool asc(T a, T b)
{
	if (a < b)
		return true;
	else
		return false;
}
template<class T>
bool desc(T a, T b)
{
	if (a < b)
		return false;
	else
		return true;
}
template<class T>
T * rightMethod(T * arr)
{
	//升序
	/*std::sort(arr, std::end(a), asc);*/
	//降序
	std::sort(arr, std::end(a), desc);
	return nullptr;
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


