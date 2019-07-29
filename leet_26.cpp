#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int del_dup_ele(int a[], int n) {
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) k++;
    else a[i - k] = a[i];
  }
  return n - k;
}

int main() {
  int a[] = {1, 1, 2, 2, 4, 4, 5, 3, 3, 3};
  int ret = del_dup_ele(a, 10);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
  std::cout << " ret " << ret;
}
