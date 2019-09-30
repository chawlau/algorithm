#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//memo[i] 表示考虑抢劫nums[i...n]所能获得的最大收益
int helper(vector<int>& nums, int index, int n, vector<int>& memo) {
  if (index >= n) return 0;

  if (memo[index] != -1)
    return memo[index];

  int res = 0;
  for (int i = index; i < n; i++) {
    res = max(res, nums[i] + helper(nums, i + 2, n, memo));
  }

  memo[index] = res;
  return res;
}

int rob(vector<int>& nums) {
  vector<int> memo1(nums.size(), -1);
  vector<int> memo2(nums.size(), -1);
  if (nums.size() <= 1)
    return nums.empty() ? 0 : nums[0];
  return max(helper(nums, 0, nums.size() - 1, memo1), helper(nums, 1, nums.size(), memo2));
}

int rob2(vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return 0;
  //memo[i]表示考虑抢劫nums[i...n-1]所能获得的最大收益
  vector<int> memo(n, -1);
  memo[n - 1] = nums[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    //mem[i]
    for (int j = i; j < n; j++)
      memo[i] = max(memo[i], nums[j] + (j + 2 < n? memo[j + 2] : 0));
  }
  return memo[0];
}

int rob3(vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return 0;
  //memo[i]表示考虑抢劫nums[0...x]所能获得的最大收益
  vector<int> memo(n, -1);
  memo[0] = nums[0];

  for (int i = 1; i < n; i++) {
    //mem[i]
    memo[i] = max(memo[i - 1], nums[i] + (i - 2 >= 0? memo[i - 2] : 0));
  }
  return memo[n - 1];
}

int main() {
  //vector<int> nums = {2,3,2, 4,5,6,7};
  vector<int> nums = {2,3,2,4};
  int ret = rob(nums);
  std::cout << ret;
}
