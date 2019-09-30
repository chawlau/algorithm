#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(const vector<int>& a, const vector<int>& b) {
  if (a.front() != b.front())
    return a.front() < b.front();
  return a.back() < b.back();
}

static bool compare(const vector<int>& a, const vector<int>& b) {
  if (a.back() != b.back())
    return a.back() < b.back();
  return a.front() < b.front();
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.size() == 0) return 0;
  sort(intervals.begin(), intervals.end(),compare);

  int res = 1;
  int pre = 0;
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i].front() >= intervals[pre].back()) {
      res ++;
      pre = i;
    }
  }
  return intervals.size() - res;
}
