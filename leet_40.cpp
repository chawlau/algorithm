#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void findPath(const vector<int>& num, vector<int>& p, int target, int idx) {
  if (target == 0) {
    res.push_back(p);
    return;
  }

  for (int i = idx; i < num.size() && target >= num[i]; i++) {
    if (i > idx && num[i] == num[i - 1]) continue;
    p.push_back(num[i]);
    findPath(num, p, target - num[i], i + 1);
    p.pop_back();
  }
  return;
}

vector<vector<int>> combinationSum2(vector<int>& num, int target) {
  if (num.size() == 0)
    return res;

  sort(num.begin(), num.end());
  vector<int> p;
  findPath(num, p, target, 0);
  return res;
}

int main() {
  vector<int> num = {10,1,2,2,7,6,1,5};
  auto res = combinationSum2(num, 9);
  for (auto& it : res) {
    for (auto& iti : it)
      cout << iti << " ";
    cout << endl;
  }
}

