#include <iostream>
#include <cstdio>
#include <cstdlib>

int num = 0;


void merge(int a[], int p, int q, int r);
void merge_sort_count(int a[], int p, int r) {
  if (p >= r) return;

  int q = (p + r) /2;

  merge_sort_count(a, p, q);
  merge_sort_count(a, q + 1, r);
  merge(a, p, q, r);
}

int count(int a[], int n) {
  merge_sort_count(a, 0, n - 1);
  return num;
}

void merge(int a[], int p, int q, int r) {
  int i = p, j = q + 1, k = 0;
  int tmp[r - p + 1];

  while (i <= q && j <= r) {
    if (a[i] <= a[j]) {
      tmp[k++] = a[i++];
    } else {
      num += (q - i + 1);
      printf("num + %d %d %d \n", q - i + 1, q, i);
      tmp[k++] = a[j++];
    }
  }

  while (i <= q) {
    tmp[k++] = a[i++];
  }

  while (j <= r) {
    tmp[k++] = a[j++];
  }

  for (int i = 0; i <= r - p; ++i)
    a[p + i] = tmp[i];
}

int main() {
  int a[] = {1, 5, 6, 2, 3, 4};
  int ret = count(a, 6);
  for (auto& it : a)
    std::cout << it;
  std::cout << std::endl;
  std::cout << " num " << ret << std::endl;
}
