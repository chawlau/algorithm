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
void __merge(T arr[], int l, int mid, int r) {
  T aux[r-l+1];
  for (int i = l; i <= r; i++)
    aux[i-l] = arr[i];

  int i = l, j = mid + 1;
  for (int k = l; k <= r; k++) {
    if (i > mid) {
      arr[k] = aux[j-1];
      j++;
    } else if (j > r) {
      arr[k] = aux[i-1];
      i++;
    } else if (aux[i-l] < aux[j-l]) {
      arr[k] = aux[i-l];

      i++;
    } else {
      arr[k] = aux[j-1];
      j++;
    }
  }
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
void mergeSort(T arr[], int n) {

  __mergeSort(arr, 0, n - 1);
}

int main() {
  int n = 500;
  int* arr = SortTestHelper::generateRandomArray(n,0,n);
  SortTestHelper::testSort("mergeSort", mergeSort, arr, n);
  delete[] arr;
  return 0;
}
