#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

//二分解决
//
int two_sum(int a[], int n, int target, int& one, int& two) {
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[l] + a[r] == target) {
      one = l;
      two = r;
      return 0;
    } else {
      if (a[l] + a[r] < target)
        l++;
      else
        r--;
    }
  }
  return -1;
}

int main() {
  int a[] = {1,2,4,5,6,7};
  int one = 0, two = 0;
  int val = two_sum(a, 6, 10, one, two);
  printf("val %d %d \n", one, two);
}
