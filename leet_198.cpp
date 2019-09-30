#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> memo;

//n进行分割，至少两部分
int max3(int a, int b, int c) {
  return max(a, max(b,c));
}

//memo[i] 表示考虑抢劫nums[i...n]所能获得的最大收益
vector<int> memo;

int helper(vector<int>& nums, int index) {
  if (index >= nums.size()) return 0;

  if (memo[index] != -1)
    return memo[index];

  int res = 0;
  for (int i = index; i < nums.size(); i++) {
    res = max(res, nums[i] + helper(nums, i + 2));
  }

  memo[index] = res;
  return res;
}

int rob2(vector<int>& nums) {
  memo = vector<int>(nums.size(), -1);
  return helper(nums, 0);
}

int helper(vector<int>& nums, int index) {
  if (index > nums.size()) return 0;

  if (memo[index] != -1)
    return memo[index];
  int res = 0;
  for (int i = index; i < nums.size(); i++) {
    res = max(res, nums[i] + helper(nums, index + 2));
  }
  memo[index] = res;
  return res;
}

int rob(vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return 0;
  //memo[i]表示考虑抢劫nums[i...n-1]所能获得的最大收益
  vector<int> memo(n, -1);
  mem[n - 1] = nums[n - 1];

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
  mem[0] = nums[0];

  for (int i = 1; i < n; i++) {
    //mem[i]
      memo[i] = max(memo[i - 1], nums[i] + (i - 2 >= 0? memo[i - 2] : 0));
  }
  return memo[n - 1];
}
