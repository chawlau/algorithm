#include <stdio.h>
#include <stdlib.h>

void print(int a[], int size) {
  int i = 0;
  for (; i < size; i++) {
    printf(" %d ", a[i]);
  }
  printf("\n");
}

void count_sort(int a[], int size) {
  int max = 0;

  int i = 0;
  for (; i < size; i++) {
    if (a[i] > max)
      max = a[i];
  }

  int* count = (int*)malloc(sizeof(int) * (max + 1));

  for (i = 0; i < size; i++) {
    count[a[i]]++;
  }
  print(count, max + 1);

  //sum
  for (i = 1; i < max + 1; i++) {
    count[i] += count[i - 1];
  }

  print(count, max + 1);

  int* res = (int*)malloc(sizeof(int) * size);

  for (i = size - 1; i >=0; i--) {
    res[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }

  memcpy(a, res, size * (sizeof(int)));
  free(res);
  free(count);
}

int main() {
  int a [10]={1,5,6,8,10,9,3,1,2,1};
  count_sort(a,10);
  int i = 0;
  for (; i < 10; i++) {
    printf("val %d ", a[i]);
  }
  printf("\n");
}
