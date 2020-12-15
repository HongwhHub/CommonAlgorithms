// SortAlgorithm.cpp : ∂®“Âøÿ÷∆Ã®”¶”√≥Ã–Úµƒ»Îø⁄µ„°£
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <time.h>
//∂‘ ˝∆˜
template<class T>
int length(T& arr);
template <class T>
T* generateRandomArray(int size, int value);
template<class T>
T * copyArray(T *arr);
template<class T>
bool asc(T a, T b);
template<class T>
bool desc(T a, T b);
template<class T>
T* rightMethod(T *arr);
template<class T>
bool isEqual(T *a, T *b);

//Ωªªª
template <class T>
void swap(T &a, T &b);
template <class T>
void swap(T *a, int i, int j);

//√∞≈›≈≈–Ú
template <class T>
void BubbleSort(T *a, int arraySize);

//—°‘Ò≈≈–Ú
template <class T>
void SelectSort(T *a, int arraySize);

//≤Â»Î≈≈–Ú
template <class T>
void InsertionSort(T *a, int arraySize);

//πÈ≤¢≈≈–Ú
template <class T>
void MergeSort(T *a);
template<class T>
void SortProcess(T *a, int left, int right);
template<class T>
void Merge(T *a, int left, int mid, int right);


int main()
{
	int *arr1;
	arr1 = generateRandomArray<int>(10, 10000);
	int *rightArray = rightMethod<int>(arr1);
	int *arr2 = copyArray<int>(arr1);
	int *arr3 = copyArray<int>(arr1);
	int *arr4 = copyArray<int>(arr1);
	BubbleSort(arr2, length(arr2));
	SelectSort(arr3, length(arr3));
	MergeSort(arr4);
	if (isEqual(arr2, rightArray))
		std::cout << "√∞≈›≈≈–Ú ok" << std::endl;
	else
		std::cout << "√∞≈›≈≈–Ú Not ok" << std::endl;
	if(isEqual(rightArray, arr3))
		std::cout << "—°‘Ò≈≈–Ú ok" << std::endl;
	else
		std::cout << "—°‘Ò≈≈–Ú Not ok" << std::endl;
	if (isEqual(arr4, rightArray))
		std::cout << "πÈ≤¢≈≈–Ú ok" << std::endl;
	else
		std::cout << "πÈ≤¢≈≈–Ú Not ok" << std::endl;
    return 0;
}

template<class T>
int length(T& arr)
{
	//cout << sizeof(arr[0]) << endl;
	//cout << sizeof(arr) << endl;
	return _msize(arr) / sizeof(arr[0]);
}

template<class T>
T * generateRandomArray(int size, int value)
{
	srand((int)time(0));
	T *arr = new T[(int)size*rand() % 10000]();
	for (int i = 0; i < length(arr); i++)
	{
		int iRand = std::rand() % 10000;
		arr[i] = (T)((value + 1)*iRand) - (T)((value)*iRand);
	}
	return arr;
}


template<class T>
T * copyArray(T *arr)
{
	T *tmp = new T[length(arr)]();
	
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
	if (a <= b)
		return false;
	else
		return true;
}
template<class T>
T * rightMethod(T * arr)
{
	//…˝–Ú
	/*std::sort(arr, std::end(a), asc);*/
	//Ωµ–Ú
	std::sort(arr, arr+length(arr), desc<T>);
	return arr;
}
template<class T>
bool isEqual(T * a, T * b)
{
	if (a == nullptr && b == nullptr)
		return true;
	if ((a == nullptr&&b != nullptr) || (a != nullptr&&b == nullptr))
		return false;
	if (length(a) != length(b))
		return false;
	for (int i = 0; i < length(a); i++)
	{
		if (a[i] != b[i])
			return false;
	}
		

	return true;
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

template<class T>
void MergeSort(T * a)
{
	if (a == nullptr || length(a) < 2)
		return;
	SortProcess(a, 0, length(a) - 1);
}

template<class T>
void SortProcess(T *a,int left,int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	SortProcess(a, left, mid);
	SortProcess(a, mid + 1,right);
	Merge(a, left, mid, right);
}

template<class T>
void Merge(T *a, int left, int mid, int right)
{
	T *tmp = new T[right - left + 1]();
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	while (p1 <= mid&&p2 <= right)
		tmp[i++] = a[p1] < a[p2] ? a[p2++] : a[p1++];
	while (p1 <= mid)
		tmp[i++] = a[p1++];
	while (p2 <= right)
		tmp[i++] = a[p2++];
	for (i = 0; i < length(tmp); i++)
		a[left + i] = tmp[i];
	delete []tmp;
}

