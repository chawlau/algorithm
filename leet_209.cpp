#include <iostream>
#include <vector>
#include <cassert>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int min_sub_array(int a[], int s, int n) {
  int l = 0, r = -1, sum = 0;

  int  res = n + 1; //有可能是整个数组之和等于s

  while (l < n) {
    if (r + 1 < n && sum < s)
      sum += a[++r];
    else
      sum -= a[l++];

    if (sum >= s)
      res = res < r - l + 1 ? res : r - l + 1;
  }

  if (res == n + 1)
    return 0;

  return res;
}

int main() {
  int a[] = {2, 3, 1, 2, 4, 3};
  int s = 7;
  int ret = min_sub_array(a, s, 6);
  std::cout << "min len " << ret << std::endl;
}



