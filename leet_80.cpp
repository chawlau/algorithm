#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

//more k ele
int rm_dup_ele(int a[], int n, int k) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (cnt < k || a[i] > a[cnt - k])
      a[cnt ++] = a[i];
  }
  return cnt;
}

int main() {
  int a[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
  int ret = rm_dup_ele(a, 10, 3);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
  std::cout << " ret " << ret;
}
