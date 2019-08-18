#include <iostream>
#include <vector>
using namespace std;

int fundNumberOfLIS(vector<int>& nums) {
  int n = nums.size();

  if (n == 0) return 0;

  vector<int> c(n, 1);
  vector<int> l(n, 1);

  for (int i = 1; i < n; ++i)
    for (int j = 0; j < i; ++j)
      if (nums[i] > nums[j]) {
        if (l[j] + 1 > l[i]) {
          l[i] = l[j] + 1;
          c[i] = c[j];
        } else if (l[j] + 1 == l[i]) {
          c[i] += c[j];
        }
      }

  int max_len = -9999999;
  for(auto& it : l)
    if (it > max_len)
      max_len = it;

  int ans = 0;
  for (int i = 0; i < n; i++)
    if (l[i] == max_len)
      ans += c[i];
  return ans;
}


int main() {
  vector<int> data;
  data.push_back(2);
  data.push_back(2);
  data.push_back(2);
  data.push_back(2);
  data.push_back(2);
  data.push_back(2);
  int ret = fundNumberOfLIS(data);
  std::cout << ret ;
}

