#include <stdio.h>
#include <stdlib.h>

int bs_search(int a[], int n, int val) {
  int lo = 0;
  int hi = n - 1;

  int mid = 0;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (val > a[mid]) {
      lo = mid + 1;
    } else if (val < a[mid]) {
      hi = mid - 1;
    } else if (a[mid] == val){
      return mid;
    }
  }
  return  -1;
}

int _bs_search(int a[], int lo, int hi, int val) {

  if (lo > hi) return -1;
  int mid = lo + (hi - lo) / 2;
  if (a[mid] == val) {
    return mid;
  } else if (a[mid] > val) {
    return _bs_search(a, mid + 1, hi, val);
  } else if (a[mid] < val) {
    return _bs_search(a, lo, mid - 1, val);
  }
}

int bs_search_re(int a[], int n, int val) {
  return _bs_search(a, 0, n - 1, val);
}

int main() {
  int a[10] = {1, 4, 5, 9, 12, 19, 21, 28, 31, 36};
  int ret = bs_search_re(a, 10, 17);
  printf("idx %d", ret);
}
