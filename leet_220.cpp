#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

/*
 Given an array of integers, find out whether there are two distinct indices i and j
 in the array such that the absolute difference between nums[i] and nums[j] is at most
 t and the absolute difference between i and j is at most k.]]
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true]
 */
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  set<int64_t> record;

  for (int i = 0; i < nums.size(); i++) {
    if (record.lower_bound((int64_t)nums[i] - (int64_t)t) != record.end() &&
        record.lower_bound((int64_t)nums[i] - (int64_t)t) <= (int64_t)nums[i] + (int64_t)t
        )
      return true;
    record.insert(nums[i]);

    if (record.size() == k + 1)
      record.erase(nums[i - k]); //容易错误点
  }
  return false;
}

int main() {
  std::vector<int> nums = {1,2,3,4,1};
  bool ret = containsNearbyDuplicate(nums, 3);
  std::cout  << " ret " << ret << std::endl;
}
