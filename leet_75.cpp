#include <iostream>
#include <vector>
#include <cassert>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void sort_colors(int nums[], int n) {
  int count[3] = {0};
  for (int i = 0; i < n; i++) {
    assert(nums[i] >= 0 && nums[i] <=2);
    count[nums[i]] ++;
  }

  int index = 0;
  for (int i = 0; i < count[0]; i++)
    nums[index++] = 0;
  for (int i = 0; i < count[1]; i++)
    nums[index++] = 1;
  for (int i = 0; i < count[2]; i++)
    nums[index++] = 2;
}

void sort_colors2(int nums[], int n) {
  //出世区间的值都为空
  int zero = -1; //nums[0..zero] == 0
  int two = n; // nums[two...n-1] = 2

  for (int i = 0; i < two; ) {
    if (nums[i] == 1)
      i++;
    else if (nums[i] == 2)
      swap(nums[i], nums[--two]);
    else {
      assert(nums[i] == 0);
      swap(nums[++zero], nums[i++]);
    }
  }
}

int main() {
  int a[] = {1, 1, 2, 2, 0, 0, 2, 1, 0, 1};
  sort_colors2(a, 10);
  for (auto& it : a)
    std::cout << it << " ";
  std::cout << std::endl;
}



