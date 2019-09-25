#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int l, int r) {
  for (int i = l+1; i <= r; i++) {
    //插入排序要比选择排序提前结束
    T e = arr[i];
    int j ;//保存元素e应该插入的位置
    for (j = i; j > l && arr[j-1] > e; j--) {
      arr[j] = arr[j-1];
    }
    arr[j] = e;
  }
}

template<typename T>
int __partition(T arr[], int l, int r) {
  swap(arr[l], arr[rand()%(r-l+1)+l]);

  T v = arr[l];
  //arr[l+1...j] < v; arr[j+1...i] > v
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (arr[i] < v)
      swap(arr[++j], arr[i]);
  }
  swap(arr[l], arr[j]);
  return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
  //if (l >= r) return;
  if (r - l <= 15) { insertionSort(arr, l, r); return;}

  int p = __partition(arr, l, r);
  __quickSort(arr, l, p - 1);
  __quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
  srand(time(NULL));
  __quickSort(arr, 0, n - 1);
}

int main() {
  int n = 1000000;
  int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
  SortTestHelper::testSort("quickSort", quickSort, arr1, n);
  delete[] arr1;

  int swapTimes = 100;
  arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
  SortTestHelper::testSort("quickSort", quickSort, arr1, n);
  return 0;
}
