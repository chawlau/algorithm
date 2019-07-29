#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int remove_elemnet(int a[], int n, int val) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != val)
      a[k++] = a[i];
  }
  return k;
}

int main() {
  int a[] = {1, 2, 4, 5, 3, 3, 3};
  int ret = remove_elemnet(a, 7, 3);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
  std::cout << " ret " << ret;
}
