#include <iostream>
#include <vector>


int lengthOfLIS(vector<int>& nums) {
  if (nums.size() == 0)
    return 0;
  //memo[i]表示以nums[i]结尾的最长上升子序列
  vector<int> memo(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++)
    for (int j = 0; j < i; j++)
      if (nums[j] < nums[i])
        memo[i] = max(memo[i], 1 + memo[j]);

  int res = 1;
  for (int i = 0; i < nums.size(); i++)
    res = max(res, memo[i]);
  return res;
}

int lengthOfLIS(vector<int>& nums) {
  if (nums.empty()) return 0;
  vector<int> memo(nums.size(), 1);

  int res = 1;
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j])
        mem[i] = max(mem[i], mem[j] + 1);
    }
    res = max(res, mem[i]);
  }
  return res;
}
