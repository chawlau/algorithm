#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int rm_ele(int a[], int n, int val) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == val) k++;
    else a[i - k] = a[i];
  }
  return n - k;
}

int main() {
  int a[] = {1, 1, 2, 2, 4, 4, 5, 3, 3, 3};
  int ret = rm_ele(a, 10, 2);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
  std::cout << " ret " << ret;
}
