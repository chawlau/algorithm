#include <iostream>
#include <vector>
#include <cassert>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void merge(int a[], int m, int b[], int n) {
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;

  while (i >= 0 && j >=0) {
    if (a[i] > b[j])
      a[k--] = a[i--];
    else
      a[k--] = b[j--];
  }

  while (j >= 0)
    a[k--] = b[j--];
}

int main() {
  int a[] = {1, 2, 3, 5, 7, 0, 0, 0, 0, 0};
  int b[] = {2, 4, 6, 8, 10};
  merge(a, 5, b, 5);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
}



