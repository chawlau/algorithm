#include <iostream>
#include <vector>

vector<vector<int>> memo;

bool helper(vector<int>& nums, int index, int sum) {
  if (sum == 0)
    return true;

  if (sum < 0 || index < 0)
    return false;

  if (memo[index][sum] != -1)
    return memo[index][sum] == 1;
  memo[index][sum] = (helper(nums, index -1, sum) ||
                      helper(nums, index -1, sum - nums[index])) ? 1 : 0;
  return memo[index][sum] == 1;
}

bool canPartition(vector<int>& nums) {
  int sum = 0;
  for (auto& t : nums) {
    assert(it > 0);
    sum += t;
  }

  if (sum % 2 != 0)
    return false;

  memo = vector<vector<int>>(nums.size(), -1);
  return helper(nums, nums.size() - 1, sum/2);
}

bool canPartition2(vector<int>& nums) {
  int sum = 0;
  for (auto& t : nums) {
    assert(it > 0);
    sum += t;
  }

  if (sum % 2 != 0)
    return false;

  int n = nums.size();
  int C = sum/2;
  vector<bool> memo(C+1, false);

  for (int  i = 0; i <= C; i++)
    memo[i] = (nums[0] == i);

  f or (int i = 1; i < n; i++)
    for (int j = C; j >= nums[i]; j--)
      memo[j] = memo[j] || memo[j - nums[i]];

  return memo[C];
}
