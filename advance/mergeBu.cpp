#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; i++) {
    //插入排序要比选择排序提前结束
    T e = arr[i];
    int j ;//保存元素e应该插入的位置
    for (j = i; j > 0 && arr[j-1] > e; j--) {
      arr[j] = arr[j-1];
    }
    arr[j] = e;
  }
}

template<typename T>
void __merge(T a[], int l, int m, int r) {
  T dumy[r-l+1];
  int i = l, j = m + 1, k = 0;
  while (i <= m && j <= r) {
    if (a[i] <= a[j])
      dumy[k++] = a[i++];
    else
      dumy[k++] = a[j++];
  }

  while (i <= m)
    dumy[k++] = a[i++];
  while (j <= r)
    dumy[k++] = a[j++];
  copy(dumy, dumy + r - l + 1, a+l);
}


template<typename T>
void __mergeSort(T arr[], int l, int r) {
  if (l >= r)
    return;

  /*
  if (r - l <= 15) {
    insertionSort(arr, l, r);
    return;
  }
  */

  int mid = (l + r) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  if (arr[mid] > arr[mid+1])
   __merge(arr, l, mid, r);
}

template<typename T>
void mergeSortBU(T arr[], int n) {
  for (int sz = 1; sz <= n; sz += sz)
    for (int i = 0; i < n; i+= sz + sz)
      //arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
      __merge(arr, i, i + sz - 1, i + sz + sz - 1);
}

int main() {
  int n = 500;
  int* arr = SortTestHelper::generateRandomArray(n,0,n);
  SortTestHelper::testSort("mergeSort", mergeSort, arr, n);
  delete[] arr;
  return 0;
}
