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

void findPath(const vector<int>& num, vector<int>& p, int idx) {
  res.push_back(p);

  for (int i = idx; i < num.size(); i++) {
    p.push_back(num[i]);
    findPath(num, p, i + 1);
    p.pop_back();
  }
  return;
}

vector<vector<int>> subsets(vector<int>& num) {
  if (num.size() == 0)
    return res;

  vector<int> p;
  findPath(num, p, 0);
  return res;
}

int main() {
  vector<int> num = {10,1,2,2,7,6,1,5};
  auto res = subsets(num);
  for (auto& it : res) {
    for (auto& iti : it)
      cout << iti << " ";
    cout << endl;
  }
}

