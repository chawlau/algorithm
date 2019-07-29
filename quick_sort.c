#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int partition(int a[], int lo, int hi) {
  int j = lo;
  int i = lo;
  for (; i < hi; ++i) {
    if (a[i] < a[hi]) {
      if (i != j) {
        swap(a, i, j);
      }
      j++;
    }
  }
  swap(a, j, hi);
  return j;
}

void quick_sort(int a[], int lo, int hi) {
  if (lo >= hi) return;

  int k = partition(a, lo, hi);
  quick_sort(a, lo, k - 1);
  quick_sort(a, k + 1, hi);
}


int find_kth_largest(int a[], int n, int k) {
  k = n - k;
  int lo = 0;
  int hi = n - 1;
  while (lo < hi) {
    int j = partition(a, lo, hi);
    if (j < k) {
      lo = j + 1;
    } else if (j > k) {
      hi = j - 1;
    } else {
      return a[j];
    }
  }
}

int main() {
  int a[] = {6,3,4,1,7,8};
  int i;
  for (i = 0; i < 6; i++) {
    printf(" data %d", a[i]);
  }
  printf("\n");

  int val = find_kth_largest(a, 6, 3);
  printf("val %d\n", val);
}
