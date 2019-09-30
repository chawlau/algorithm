#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>
#include <unordered_set>

using namespace std;

vector<vector<int>> res;

//C(n, k) 当前找到的组合存在c中
void generateCombination(int n, int k, int start, vector<int>& c) {
  if (c.size() == k) {
    res.push_back(c);
    return;
  }

  for (int i = start; i <= n - (k - c.size()) + 1; i++) {
    c.push_back(i);
    generateCombination(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

vector<vector<int>> combine(int n, int k) {
  res.clear();

  if (n <= 0 || k <= 0 || k > n)
    return res;

  vector<int> c;
  generateCombination(n, k, 1, c);
  return res;
}

int main() {
}

void generateCombination(int n, int k, int start, vector<int>& c) {
  if (c.size() == k) {
    res.push_back(c);
    return;
  }

  for (int i = start ; i <= n; i++) {
    c.push_back(i);
    generateCombination(n, k, i + 1, c);
    c.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  if (k > n || k <= 0 || n <= 0)
    return res;

  vector<int> c;
  generateCombination(n, k, 1, c;)
}

