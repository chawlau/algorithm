#ifndef _CPUT_H_
#define _CPUT_H_
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort2(T arr[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[minIndex])
        minIndex = j;
    swap(arr[i], arr[minIndex]);
  }
}

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
#endif
