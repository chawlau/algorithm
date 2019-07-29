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

int partition(int a[], int lo, int hi) {
  int i = lo;
  int j = lo;

  for(; i < hi; i++) {
    if (a[i] < a[hi]) {
      if (i != j)
        swap(a[i], a[j]);
      j++;
    }
  }
  swap(a[j], a[hi]);
  return j;
}

int find_kth_largest(int a[], int n, int k) {
  k = n - k;
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int j = partition(a, lo, hi);
    if (j < k)
      lo = j + 1;
    else if (j > k)
      hi = j - 1;
    else
      return a[j];
  }
}

int main() {
  int a[] = {6,3,4,1,7,8};
  for (int i = 0; i < 6; i++) {
    printf(" data %d", a[i]);
  }
  printf("\n");

  int val = find_kth_largest(a, 6, 2);
  printf("val %d\n", val);
}
