#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void findPath(const vector<int>& candidates, vector<int>& p, int target, int idx) {
  if (target == 0) {
    res.push_back(p);
    return;
  }

  for (int i = idx; i < candidates.size() && target >= candidates[i]; i++) {
    p.push_back(candidates[i]);
    findPath(candidates, p, target - candidates[i], i);
    p.pop_back();
  }
  return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  if (candidates.size() == 0)
    return res;

  sort(candidates.begin(), candidates.end());
  vector<int> p;
  findPath(candidates, p, target, 0);
  return res;
}

