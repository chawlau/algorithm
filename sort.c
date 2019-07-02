#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int n) {
  if (n <= 1) return;
  int i, j = 0;
  int max = 0;
  for (i = 0; i < n ; ++i) {
    int flag = 0;
    for (j = 0; j < n - i - 1; ++j) {
      if (a[j] > a[j+1]) {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

void insert_sort(int a[], int n) {
  if (n <= 1) return;

  int i, j = 0;
  for (i = 1; i < n; ++i) {
    int val = a[i];
    for (j = i - 1; j >= 0; j--) {
      if (val < a[j]) {
        a[j+1] = a[j];
      } else {
        break;
      }
    }
    a[j+1] = val;
  }
}

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void select_sort(int a[], int n) {
  if (n <= 1) return;

  int i,j = 0;
  int min_idx = 0;
  for (i = 0; i < n; i++) {
    min_idx = i;
    for (j = i; j < n; j++) {
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    swap(a, i, min_idx);
  }
}

int main() {
  int a[] = {6,3,4,1,7,8};
  int i = 0;
  select_sort(a, 6);
  for (; i < 6; i++) {
    printf(" data %d", a[i]);
  }
  printf("\n");
}
