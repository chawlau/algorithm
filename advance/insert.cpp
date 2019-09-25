#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[minIndex])
        minIndex = j;
    swap(arr[i], arr[minIndex]);
  }
}

template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; i++) {
    //插入排序要比选择排序提前结束
    for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
        swap(arr[j], arr[j-1]);
    }
  }
}

template<typename T>
void insertionSort2(T arr[], int n) {
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
void insertionSort3(T arr[], int n);

int main() {
  //Student d[4] = {{"D", 90},{"C", 100},{"B", 95},{"A", 95}};
  int n = 50000;
  int* arr = SortTestHelper::generateRandomArray(n, 0, n);
  int* arr2 = SortTestHelper::copyIntArray(arr, n);
  //SortTestHelper::testSort("insetionSort", insertionSort, arr, n);
  SortTestHelper::testSort("insetionSort3", insertionSort3, arr, n);
  SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);
  delete []arr;
  delete []arr2;
}

template<typename T>
void insertionSort3(T arr[], int n) {
  for (int i = 1; i < n; i++) {
    T e = arr[i];
    int j;
    for (j = i; j > 0 && e < arr[j-1]; j--)
      arr[j] = arr[j-1];
    arr[j] = e;
  }
}

