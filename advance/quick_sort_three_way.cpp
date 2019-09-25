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
void __quickSort(T arr[], int l, int r) {
  if (l >= r) return;
  //if (r - l <= 15) { insertionSort(arr, l, r); return;}

  //partition
  swap(arr[l], arr[rand()%(r-l+1)+1]);
  T v = arr[l];

  int lt = l; //arr[l+1...lt] < v
  int gt = r + 1; //arr[gt...r] > v
  int i = l + 1; //arr[lt+1...i) == v

  while (i < gt) {
    if (arr[i] < v) {
      swap(arr[i], arr[lt+1]);
      i++;
      lt++;
    } else if (arr[i] > v){
      //i的指针不需要动
      swap(arr[i], arr[gt-1]);
      gt--;
    } else {
      i++;
    }
  }
  swap(arr[l], arr[lt]);
  __quickSort(arr, l, lt-1);
  __quickSort(arr, gt, r);
}

template<typename T>
void quickSort(T arr[], int n) {
  srand(time(NULL));
  __quickSort(arr, 0, n - 1);
}

int main() {
  int n = 10;
  int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
  SortTestHelper::testSort("quickSort", quickSort, arr1, n);
  delete[] arr1;

  int swapTimes = 100;
  arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
  SortTestHelper::testSort("quickSort", quickSort, arr1, n);
  delete[] arr1;

  arr1 = SortTestHelper::generateRandomArray(n,0,10);
  SortTestHelper::testSort("quickSort", quickSort, arr1, n);
  delete[] arr1;
  return 0;
}
