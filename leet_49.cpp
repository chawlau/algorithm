#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>

/*
leetcode 49
Given an array of strings, group anagrams together
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
*/
using namespace std;

string strSort(string s) {
  int cnt[26] = {0};

  for (char c : s)
    cnt[c - 'a']++;

  string ret;
  for (int i = 0; i < 26; i++)
    ret += string(cnt[i], i + 'a');
  return ret;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
  std::map<std::string, vector<string> > data;
  for (string s : strs) {
    data[strSort(s)].push_back(s);
  }

  vector<vector<string> > ret;

  for (auto& p : data) {
    ret.push_back(p.second);
  }
  return ret;
}

int main() {
  vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string> > ret = groupAnagrams(str);

  for (auto& it : ret)
    for (auto& st : it)
      std::cout << st << endl;
}
