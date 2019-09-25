#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
  for( int i = 1 ; i < n ; i ++ ) {
    T e = arr[i];
    int j;
    for (j = i; j > 0 && arr[j-1] > e; j--)
      arr[j] = arr[j-1];
    arr[j] = e;
  }
  return;
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    //插入排序要比选择排序提前结束
    T e = arr[i];
    int j ;//保存元素e应该插入的位置
    for (j = i; j > l && arr[j-1] > e; j--)
      arr[j] = arr[j-1];
    arr[j] = e;
  }
  return;
}

template<typename T>
void __merge(T a[], int l, int m, int r) {
  T dumy[r-l+1];
  int i = l, j = m + 1, k = 0;
  while (i <= m && j <= r) {
    if (a[i] < a[j])
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
  /*
  if (l >= r)
    return;
    */

  if (r - l <= 15) {
    insertionSort(arr, l, r);
    return;
  }

  int mid = (l + r) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  //对于近乎有序的数组非常有效，但是一般情况下有一定的性能损失
  if (arr[mid] > arr[mid+1])
    __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
  __mergeSort(arr, 0, n - 1);
}

int main() {
  int n = 100000;
  int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
  int* arr2 = SortTestHelper::copyIntArray(arr1, n);
  SortTestHelper::testSort("mergeSort", mergeSort, arr1, n);
  SortTestHelper::testSort("mergeSort", insertionSort, arr2, n);
  delete[] arr1;
  delete[] arr2;
  return 0;
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

  while (j <= r)
    dumy[k++] = a[j++];
  while (i <= m)
    dumy[k++] = a[i++];
  copy(dumy, dumy + r - l + 1, a + l);
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
  for (int i = l + 1; i < r ; i++) {
    T e = arr[i];
    int j;
    for (j = i; j > l && arr[j-1] > e; j--)
      arr[j] = arr[j-1];
    arr[j] = e;
  }
}

