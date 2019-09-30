#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void findPath(const vector<int>& nums, vector<int>& p, int idx) {
  res.push_back(p);

  for (int i = idx; i < nums.size(); i++) {
    p.push_back(nums[i]);
    findPath(nums, p, i + 1);
    p.pop_back();
  }
  return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  if (nums.size() == 0)
    return res;

  vector<int> p;
  findPath(nums, p, 0);
  return res;
}

int main() {
  vector<int> nums = {10,1,2,2,7,6,1,5};
  sort(nums.begin(), nums.end());
  auto res = subsetsWithDup(nums);
}

