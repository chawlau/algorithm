#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <functional>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);

int main()
{
  vector<int> nums = {1,1,1,2,2};
  auto ret = topKFrequent(nums, 2);
  for (auto& it : ret)
    printf(" %d ", it);
  printf("\n");
  return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
  assert(k > 0);

  unordered_map<int, int> freq;
  for (int i = 0; i < nums.size(); i++)
    freq[nums[i]]++;

  assert(k <= freq.size());
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

  for (auto iter = freq.begin(); iter != freq.end(); iter++) {
    if (pq.size() == k) {
      if (iter->second > pq.top().first) {
        pq.pop();
        pq.push(make_pair(iter->second, iter->first));
      }
    } else
      pq.push(make_pair(iter->second, iter->first));
  }

  vector<int> res;
  while (!pq.empty()) {
    res.push_back(pq.top().second);
    pq.pop();
  }
  return res;
}

vector<int> topKFrequentII(vector<int>& nums, int k) {
  assert(k > 0);

  unordered_map<int, int> freq;
  for (int i = 0; i < nums.size(); i++)
    freq[nums[i]]++;

  assert(k <= freq.size());
  priority_queue<pair<int, int>> pq;

  vector<int> res;
  for (auto iter = freq.begin(); iter != freq.end(); iter++) {
    pq.push(make_pair(iter->second, iter->first));
    if (pq.size() > freq.size() - k) {
      res.push_back(pq.top().second);
      pq.pop();
    }
  }

  return res;
}
