// BucketProblem.cpp : 定义控制台应用程序的入口点。
//
/*
	给定一个数组， 求如果排序之后， 相邻两数的最大差值， 要求时
 间复杂度O(N)， 且要求不能用非基于比较的排序。
*/

#include "stdafx.h"
#include <algorithm>
#include<iostream>


int maxGap(int *arr);
int length(int *arr);
int bucket(long num, long lenth, long min, long max);
int getRightMax(int *arr);
int main()
{
	int *arr = new int[5]();
	*(arr) = 1;
	*(arr + 1) = 5;
	*(arr + 2) = 9;
	*(arr + 3) = 6;
	*(arr + 4) = 3;
	int maxg = maxGap(arr);
	int right = getRightMax(arr);
	if (right == maxg)
		std::cout << "ok" << std::endl;
    return 0;
}

int maxGap(int * arr)
{
	if (arr == nullptr || length(arr) < 2)
		return 0;
	int len = length(arr);
	int min = *std::min_element(arr, arr + len);
	int max = *std::max_element(arr, arr + len);
	if (min == max)
		return 0;
	bool *hasNum = new bool[len+1];
	int *maxs = new int[len + 1];
	int *mins = new int[len + 1];
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		index = bucket(arr[i], len, min, max);
		maxs[index] = hasNum[index] ? std::max(maxs[index], arr[i]) : arr[i];
		mins[index] = hasNum[index] ? std::min(mins[index], arr[i]) : arr[i];
		hasNum[index] = true;
	}
	int result = 0;
	int maxNum = maxs[0];
	for (int i = 1; i < len; i++)
	{
		if (hasNum[i])
		{
			result = std::max(result, mins[i] - maxNum);
			maxNum = maxs[i];
		}
	}
	return result;
}

int length(int *arr)
{
	return _msize(arr) / sizeof(arr[0]);
}

int bucket(long num, long lenth, long min, long max)
{
	return (int)((num - min) * lenth / (max - min));
}

int getRightMax(int *arr)
{
	int len = length(arr);
	std::sort(arr, arr + len);
	return 0;
}
