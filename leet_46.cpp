#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>
#include <unordered_set>

using namespace std;

vector<vector<int>> res;
vector<bool> used = {false};

void generatPermutation(const vector<int>& nums, int index, vector<int>& p) {
  if (index == nums.size()) {
    res.push_back(p);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
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
  generatPermutation(nums, 0, p);
  return res;
}

int main() {
}
