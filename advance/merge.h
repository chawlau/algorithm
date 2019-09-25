#include <iostream>
#include "SortTestHelper.h"
#include "insert.h"

using namespace std;

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
