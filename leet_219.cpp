#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <unordered_set>

/*
 Given an array of integers and an integer k, find out whether 
 there are two distinct indices i and j in the array such that nums[i] = nums[j] and 
 the absolute difference between i and j is at most k.]]
Input: nums = [1,2,3,1], k = 3
Output: true]
*/

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_set<int> record;

  for (int i = 0; i < nums.size(); i++) {
    if (record.find(nums[i]) != record.end())
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
