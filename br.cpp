#include <iostream>
#include <cmath>
#include <cassert>
#include <time.h>
#include <cstdio>
#include <cstdlib>

template <typename T>
int binary_search(T a[], int n, T target) {
  int l = 0, r = n - 1; //在范围中寻找target

  while (l <= r) { // l == r时,[l...r]区间依然有效
    int mid = l + (r - l) / 2;
    if (a[mid] == target)
      return mid;
    else if (target > a[mid])
      l = mid + 1;
    else if (target < a[mid])
      r = mid - 1;
  }

  return -1;
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10};

  int i = binary_search(a, 10, 12);
  printf(" i = %d \n", i);
}
