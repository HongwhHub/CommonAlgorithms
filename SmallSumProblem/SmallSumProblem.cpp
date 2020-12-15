// SmallSumProblem.cpp : 定义控制台应用程序的入口点。
//小和问题

/*
在一个数组中， 每一个数左边比当前数小的数累加起来， 叫做这个数组的小和。 求一个数组的小和。
   例子：
	[1, 3, 4, 2, 5]
	1左边比1小的数， 没有；
	3左边比3小的数， 1；
	4左边比4小的数， 1、 3；
	2左边比2小的数， 1；
	5左边比5小的数， 1、 3、 4、 2；
	所以小和为1 + 1 + 3 + 1 + 1 + 3 + 4 + 2 = 16
*/

#include "stdafx.h"
#include<iostream>

template<class T>
int length(T& arr)
{
	//cout << sizeof(arr[0]) << endl;
	//cout << sizeof(arr) << endl;
	return _msize(arr) / sizeof(arr[0]);
}

template<class T>
T Merge(T *a, int left, int mid, int right)
{
	T *tmp = new T[right - left + 1]();
	T sum = 0;
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	while (p1 <= mid&&p2 <= right)
	{
		sum += a[p1] < a[p2] ? (right - p2 + 1)*a[p1] : 0;
		tmp[i++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
	}
		
	while (p1 <= mid)
		tmp[i++] = a[p1++];
	while (p2 <= right)
		tmp[i++] = a[p2++];
	for (i = 0; i < length(tmp); i++)
		a[left + i] = tmp[i];
	delete[]tmp;
	return sum;
}

template<class T>
T SortProcess(T *a, int left, int right)
{
	if (left == right)
		return 0;
	int mid = (left + right) / 2;
	return SortProcess<T>(a, left, mid) +
		SortProcess<T>(a, mid + 1, right) +
		Merge<T>(a, left, mid, right);
}

template<class T>
T MergeSort(T * a)
{
	if (a == nullptr || length(a) < 2)
		return 0;
	return SortProcess<T>(a, 0, length(a) - 1);
}



int main()
{
	int *a = new int[5];
	*a = 1;
	*(a + 1) = 3;
	*(a + 2) = 4;
	*(a + 3) = 2;
	*(a + 4) = 5;
	std::cout << MergeSort<int>(a);
	delete[]a;
    return 0;
}

