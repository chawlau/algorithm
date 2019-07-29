#include <iostream>
#include <vector>

void move_zero(std::vector<int>& nums) {
  std::vector<int> dumy;

  int k = 0; //nums [0,k) 元素均为非0元素
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i])
      nums[k++] = nums[i];
  }

  for (int i = k; i < nums.size(); i++)
    nums[i] = 0;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void move_zero2(std::vector<int>& nums) {

  int k = 0; //nums [0,k) 元素均为非0元素
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i])
      if (i != k) //相同元素不必交换
        swap(nums[k++], nums[i]);
      else
        k++;
  }
}

int remove_elemnet(int a[], int n, int val) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != val)
      a[k++] = a[i]
  }
  return k;
}


int main() {
  std::vector<int> data;
  data.push_back(1);
  data.push_back(0);
  data.push_back(2);
  data.push_back(0);
  data.push_back(4);
  data.push_back(0);

  for (auto& it : data)
    std::cout << it << " ";
  std::cout << std::endl;
}
