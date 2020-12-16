// NetherLandsFlags.cpp : �������̨Ӧ�ó������ڵ㡣
//������������
/*
	����һ������arr�� ��һ����num�� ���С��num�������������
��ߣ� ����num��������������м䣬 ����num�������������
�ұߡ�
	Ҫ�����ռ临�Ӷ�O(1)�� ʱ�临�Ӷ�O(N)
*/

#include "stdafx.h"
#include<iostream>

template <typename T>
void swap(T *a, int l, int r);

template <typename T>
void partition(T *arr,int L,int R,T num);

int main()
{
	int num = 8;
	int i = 0;
	int *arr = new int[5]();
	*(arr + i) = 6;
	i++;
	*(arr + i) = 9;
	i++;
	*(arr + i) = 4;
	i++;
	*(arr + i) = 3;
	i++;
	*(arr + i) = 8;
	partition(arr, 0, 4, 8);
	for (int k = 0; k < 5; k++)
		std::cout << *(arr + k) <<" ";
    return 0;
}

template <typename T>
void swap(T *a,int l,int r)
{
	T tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}

template<typename T>
void partition(T * arr, int L, int R, T num)
{
	int less = L - 1;
	int more = R + 1;
	int curr = L;
	while (curr < more)
	{
		if (arr[curr] < num)
			swap(arr, ++less, curr++);
		else if (arr[curr] > num)
			swap(arr, --more, curr);
		else
			curr++;
	}
}
