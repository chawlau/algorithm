#include "heap.hpp"
#include "merge.h"
#include "quick_sort.h"

template<typename T>
void heapSort1(T arr[], int n) {

  MaxHeap<T> maxheap = MaxHeap<T>(n);

  for (int i = 0; i < n; i++)
    maxheap.insert(arr[i]);

  for( int i = n-1 ; i >= 0 ; i-- )
    arr[i] = maxheap.extractMax();
}

template<typename T>
void heapSort2(T arr[], int n) {

  MaxHeap<T> maxheap = MaxHeap<T>(arr, n);

  for( int i = n-1 ; i >= 0 ; i-- )
    arr[i] = maxheap.extractMax();
}

template<typename T>
void __shiftDown(T arr[], int n, int k) {
  while (2*k + 1 < n) {
    int i = 2*k + 1;
    if (i + 1 < n && arr[i+1] > arr[i])
      i += 1;
    if (arr[k] >= arr[i])
      break;
    swap(arr[k], arr[i]);
    k = i;
  }
}

template<typename T>
void heapSort3(T arr[], int n) {

  for (int i = (n-1)/2; i >=0; i--)
    __shiftDown(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    __shiftDown(arr, i, 0);
  }
}

template<typename T>
void heapSort4(T arr[], int n);


int main() {
  int n = 1000000;

  // 测试1 一般性测试
  cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
  int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
  int* arr2 = SortTestHelper::copyIntArray(arr1, n);
  int* arr3 = SortTestHelper::copyIntArray(arr1, n);
  int* arr4 = SortTestHelper::copyIntArray(arr1, n);
  int* arr5 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
  SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
  //SortTestHelper::testSort("Insert Sort", insertionSort, arr3, n);
  SortTestHelper::testSort("Heap Sort 1", heapSort1, arr3, n);
  SortTestHelper::testSort("Heap Sort 2", heapSort2, arr4, n);
  SortTestHelper::testSort("Heap Sort 3", heapSort4, arr5, n);
}

template<typename T>
void __shiftDown2(T arr[], int n, int k) {
  while (2*k + 1 < n) {
    int i = 2* k + 1;
    if (i + 1 < n && arr[i + 1] > arr[i])
      i++;
    if (arr[k] >= arr[i])
      break;
    swap(arr[k], arr[i]);
    k = i;
  }
}

template<typename T>
void heapSort4(T arr[], int n) {
  for (int i = (n-1)/2; i >=0; i--)
    __shiftDown2(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    __shiftDown2(arr, i, 0);
  }
}

