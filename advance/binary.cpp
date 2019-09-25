#include "heap.hpp"
#include "merge.h"
#include "quick_sort.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
  //在arr[l..r]中查找target
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
      return mid;
    if (target < arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }
}

//递归
//
int main() {
// 测试1 一般性测试
  cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
  int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
  int* arr2 = SortTestHelper::copyIntArray(arr1, n);
}

