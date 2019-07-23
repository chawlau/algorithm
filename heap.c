#include <stdio.h>
#include <stdlib.h>

void print(int a[]) {
  int i = 0;
  for (; i < 10; i++) {
    printf(" %d ", a[i]);
  }
  printf("\n");
}

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void heapify(int a[], int n, int i) {
  while (1) {
    int max = i;
    if (2 * i + 1 < n && a[i] < a[2 * i + 1]) max = 2*i +1;

    if (2 * i + 2 < n && a[max] < a[2 * i + 2]) max = 2*i +2;

    if (max == i) break;

    swap(a, i, max);
    i = max;
  }
}

void build_heap(int a[], int n) {
  int i;
  for (i = (n - 1)/2; i >= 0; --i) {
    heapify(a, n, i);
  }
}

void heap_sort(int a[], int n) {
  build_heap(a, n);

  print(a);
  int k = n - 1;

  while (k > 0) {
    swap(a, 0, k);
    --k;
    heapify(a, k, 0);
    print(a);
  }
}

int main() {
  int a[] = {7, 5, 19, 8, 4, 1, 20, 13, 16, 15};
  heap_sort(a, 10);
  print(a);
}
