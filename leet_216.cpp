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

void findPath(int k, int n, vector<int>& p, int idx) {
  if (k == 0 && n == 0) {
    res.push_back(p);
    return;
  }

  for (int i = idx; i <= n && i <= 10 - k ; i++) {
    p.push_back(i);
    findPath(k - 1, n - i, p, i + 1);
    p.pop_back();
  }
  return;
}

vector<vector<int>> combinationSum3(int k, int n) {
  if (k < n || n < 0 || k < 0)
    return res;
  vector<int> p;
  findPath(k, n, p, 1);
  return res;
}

int main() {
  vector<int> num = {10,1,2,2,7,6,1,5};
  auto res = combinationSum3(10, 2);
  for (auto& it : res) {
    for (auto& iti : it)
      cout << iti << " ";
    cout << endl;
  }
}

