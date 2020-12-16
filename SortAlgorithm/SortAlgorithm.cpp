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

//归并排序
template <class T>
void MergeSort(T *a);
template<class T>
void SortProcess(T *a, int left, int right);
template<class T>
void Merge(T *a, int left, int mid, int right);

//快速排序(仿荷兰国旗问题实现)
template <typename T>
void QSwap(T *a, int l, int r);
template <typename T>
void Partition(T * arr, int L, int R, int *tmp);
template <typename T>
void QuickSort(T *arr, int L, int R);

//随机快速排序
template <typename T>
void RandomQuickSort(T *arr, int L, int R);

//堆排序
template <typename T>
void HeapSort(T *arr);
template <typename T>
void HeapInsert(T *arr, int index);
template <typename T>
void Heapify(T *arr, int index, int size);



int main()
{
	int *arr1;
	arr1 = generateRandomArray<int>(11, 10000);
	int *rightArray = rightMethod<int>(arr1);
	int *arr2 = copyArray<int>(arr1);
	int *arr3 = copyArray<int>(arr1);
	int *arr4 = copyArray<int>(arr1);
	int *arr5 = copyArray<int>(arr1);
	int *arr6 = copyArray<int>(arr1);
	int *arr7 = copyArray<int>(arr1);

	BubbleSort(arr2, length(arr2));
	if (isEqual(arr2, rightArray))
		std::cout << "冒泡排序 ok" << std::endl;
	else
		std::cout << "冒泡排序 Not ok" << std::endl;

	SelectSort(arr3, length(arr3));
	if (isEqual(rightArray, arr3))
		std::cout << "选择排序 ok" << std::endl;
	else
		std::cout << "选择排序 Not ok" << std::endl;

	MergeSort(arr4);
	if (isEqual(arr4, rightArray))
		std::cout << "归并排序 ok" << std::endl;
	else
		std::cout << "归并排序 Not ok" << std::endl;

	QuickSort(arr5, 0, length(arr5) - 1);	
	if (isEqual(arr5, rightArray))
		std::cout << "快速排序 ok" << std::endl;
	else
		std::cout << "快速排序 Not ok" << std::endl;

	RandomQuickSort(arr6, 0, length(arr6) - 1);
	if (isEqual(arr6, rightArray))
		std::cout << "随机快速排序 ok" << std::endl;
	else
		std::cout << "随机快速排序 Not ok" << std::endl;

	HeapSort(arr7);
	if (isEqual(arr7, rightArray))
		std::cout << "堆排序 ok" << std::endl;
	else
		std::cout << "堆排序 Not ok" << std::endl;

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
	T *arr = new T[(int)size*std::rand() % 1000]();//(int)size*std::rand() % 10000
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
	//升序
	/*std::sort(arr, std::end(a), asc);*/
	//降序
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
	int mid = (left+right)/2;
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

template <typename T>
void QSwap(T *a, int l, int r)
{
	T tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}

template<typename T>
void Partition(T * arr, int L, int R,int *tmp)
{
	int less = L - 1;
	int more = R;
	int curr = L;
	while (curr < more)
	{
		if (arr[curr] > arr[R])
			QSwap(arr, ++less, curr++);
		else if (arr[curr] < arr[R])
			QSwap(arr, --more, curr);
		else
			curr++;
	}
	*tmp=less+1;
	*(tmp + 1) = more;
	QSwap(arr, more, R);
}

template<typename T>
void QuickSort(T * arr, int L, int R)
{
	if (L < R)
	{
		int *tmp=new int[2]; 
		Partition(arr, L, R, tmp);
		QuickSort(arr, L, *tmp - 1);
		QuickSort(arr, *(tmp + 1) + 1, R);
		delete[]tmp;
	}
}

template<typename T>
void RandomQuickSort(T * arr, int L, int R)
{
	if (L < R)
	{
		srand((int)time(0));
		QSwap(arr, L + rand() % (R - L + 1) + L, R);
		int *tmp = new int[2];
		Partition(arr, L, R, tmp);
		QuickSort(arr, L, *tmp - 1);
		QuickSort(arr, *(tmp + 1) + 1, R);
		delete[]tmp;
	}
}

template<typename T>
void HeapSort(T * arr)
{
	if (arr == nullptr || length(arr) < 2)
		return;
	//形成小根堆
	for (int i = 0; i < length(arr); i++)
		HeapInsert(arr, i);
	int heapSize = length(arr);
	swap(arr, 0, --heapSize);
	while (heapSize>0)
	{
		Heapify(arr, 0, heapSize);
		swap(arr, 0, --heapSize);
	}
}

template<typename T>
void HeapInsert(T * arr, int index)
{
	while (arr[index] < arr[(index - 1) / 2]) {
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

template<typename T>
void Heapify(T * arr, int index,int size)
{
	int left = index * 2 + 1;
	while (left < size) {
		int largest = left + 1 < size && arr[left + 1] < arr[left] ? left + 1 : left;
		largest = arr[largest] < arr[index] ? largest : index;
		if (largest == index) {
			break;
		}
		swap(arr, largest, index);
		index = largest;
		left = index * 2 + 1;
	}
}
