#include <stdio.h>
#include <stdlib.h>

int bs_first(int a[], int n, int val) {
  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    if (a[mid] == val) {
      if (mid == 0 || a[mid - 1] != val) {
        return mid;
      }
      hi = mid - 1;
    } else if (a[mid] > val) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
}

int bs_first_large(int a[], int n, int val) {
  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    if (a[mid] >= val) {
      if (mid == 0 || a[mid - 1] < val) {
        return mid;
      }
      hi = mid - 1;
    } else if (a[mid] > val) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
}


int bs_last(int a[], int n, int val) {
  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    if (a[mid] == val) {
      if (mid == n - 1 || a[mid + 1] != val) {
        return mid;
      }
      lo = mid + 1;
    } else if (a[mid] > val) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

int bs_last_less(int a[], int n, int val) {
  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (a[mid] > val) {
      hi = mid - 1;
    } else {
      if (mid == n - 1 || a[mid + 1] > val) {
        return mid;
      }
      lo = mid + 1;
    }
  }

  return -1;
}

int main() {
  int a[10] = {1, 4, 5, 6, 7, 8, 8, 8, 8, 10};
  int ret = bs_last(a, 10, 8);
  printf("idx %d \n", ret);
}
