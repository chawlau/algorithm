#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void helper(vector<int> nums, int idx) {
  if (idx == nums.size()) {
    res.push_back(nums);
    return;
  }

  for (int i = idx; i < nums.size(); i++) {
    if (idx != i && nums[i] == nums[idx])
      continue;
    swap(nums[idx], nums[i]);
    helper(nums, idx + 1);
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  if (nums.empty()) return res;
  helper(nums, 0);
  return res;
}

void generatPermutation(const vector<int>& nums, int index, vector<int>& p) {
  if (index == nums.size()) {
    res.push_back(p);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if(i > 0 && nums[i-1] == nums[i] && !used[i-1])
      continue;

    if (!used[i]) {
      p.push_back(nums[i]);
      used[i] = true;
      generatPermutation(nums, index + 1, p);
      p.pop_back();
      used[i] = false;
    }
  }
  return;
}

vector<vector<int>> permute(vector<int>& nums) {
  if (nums.size() == 0)
    return res;

  used = vector<bool>(nums.size(), false);
  vector<int> p;
  sort(nums.begin(), nums.end());
  generatPermutation(nums, 0, p);
  return res;
}

