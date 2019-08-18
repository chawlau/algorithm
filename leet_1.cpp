#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> record;
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (record.find(complement) != record.end()) {
      int res[2] = {i, record[complement]};
      return vector<int>(res, res + 2);
    }

    record[nums[i]] = i;i
  }
}

int main() {
  std::string s = "tree";
  std::string p = sort_char_freq(s);

  std::cout << "sort ret " << p << std::endl;
}



