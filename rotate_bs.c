#include <stdio.h>
#include <stdlib.h>

int rotate_bs(int a[], int n, int val) {
  int lo = 0, hi = n - 1;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] > a[hi])
      lo = mid + 1;
    else
      hi = mid;
  }

  printf("smallest idx %d \n", lo);
  int rot = lo;
  lo = 0;
  hi = n - 1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int real_mid = (mid + rot) % n;
    if (a[real_mid] == val)
      return real_mid;
    else if (a[real_mid] > val)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return -1;
}

int main() {
  int a[7] = {4,5,6,7,0,1,2};
  int ret = rotate_bs(a, 7, 5);
  printf("idx %d \n", ret);
}
