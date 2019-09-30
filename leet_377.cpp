#include <iostream>
#include <vector>

using namespace std;


int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target + 1);
  dp[0] = 1;

  sort(nums.begin(), nums.end());
  for (int i = 1; i <= target; i++) {
    for (auto& it : nums) {
      if (it > i) break;
      dp[i] += dp[i-it];
    }
  }
  return dp.back();
}
