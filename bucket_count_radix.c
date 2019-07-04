#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void radix_sort(int a[], int n, int bite_num) {
  int i;

  int radix = 10;
  int j;
  int* count = (int*)malloc(10 * 4);
  int* res = (int*)malloc(n * 4);
  int index;
  for (i = 0; i < bite_num; ++i) {
    radix = pow(10, i);
    memset(count, 0, 4 * 10);

    for (j = 0; j < n; j++) {
      index = (a[j] / radix) % 10;
      count[index]++;
    }

    for(j = 1; j < 10; j++) {
      count[j] += count[j - 1];
    }

    for (j = n - 1; j >= 0; j--) {
      index = (a[j] / radix) % 10;
      res[count[index] - 1] = a[j];
      count[index] --;
    }
    memcpy(a, res, 4 * n);
  }
}

void radix_test() {
  int a[10] = {123,12341,1232134,124,236,128,1112313129,98,9,8989};
  radix_sort(a, 10, 10);
  print(a, 10);
}

int main() {
  int a [10]={1,5,6,8,10,9,3,1,2,1};
  count_sort(a,10);
  int i = 0;
  for (; i < 10; i++) {
    printf("val %d ", a[i]);
  }
  printf("\n");

  radix_test();
}
