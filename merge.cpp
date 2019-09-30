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

int main() {
  //Student d[4] = {{"D", 90},{"C", 100},{"B", 95},{"A", 95}};
  int n = 10000;
  int* arr = SortTestHelper::generateRandomArray(n, 0, n);
  //selectionSort(arr, n);
  SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
}
