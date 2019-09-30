#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector p(nums.size(), 1);
    vector q(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j])
          p[i] = max(p[i], p[j] + 1);
        else if (nums[i] < nums[j])
          p[j] = max(p[j], p[i] + 1);
      }
    }

    return max(p.back(), q.back());
  }
};

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int p, q = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i-1])
        p = q + 1;
      else if (nums[i] < nums[i-1])
        q = p + 1;
    }
    return min(nums.size(), max(p, q));
  }
};
