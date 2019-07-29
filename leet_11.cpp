#include <iostream>
#include <cstdio>
#include <cstdlib>

int max_area(int a[], int n) {
  int i = 0, j = n - 1, water = 0;
  while (i < j) {
    int min = (a[i] < a[j] ? a[i] : a[j]);
    int w = (j - i) * min;
    if (w > water) water = w;

    while (a[i] <= min && i < j) i++;

    while (a[j] <= min && i < j) j--;
  }
  return water;
}

int main() {
  int a[] = {1,8,6,2,5,4,8,3,7};
  int area = max_area(a, 9);
  printf("area %d ", area);
}
