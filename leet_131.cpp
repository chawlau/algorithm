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

vector<vector<string>> res;

bool isPalindrome(const string& s, int start, int end) {
  while (start < end)
    if (s[start++] != s[end--])
      return false;
  return true;
}

void helper(const string& s, vector<string>& path, int idx) {
  if (idx == s.size()) {
    res.push_back(path);
    return;
  }

  for (int i = idx; i < s.size(); i++) {
    if (isPalindrome(s, idx, i)) {
      string dumy = s.substr(idx, i - idx + 1);
      path.push_back(dumy);
      helper(s, path, idx +1);
      path.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<string> path;
  if (s.empty()) return res;
  helper(s, path, 0);
  return res;
}
