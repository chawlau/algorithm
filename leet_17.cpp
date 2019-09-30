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

const string letterMap[10] = {
  " ",
  "",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz",
};

//s保存了从digits[0...index-1]翻译得到的字符串
//寻找和digits[index]匹配的字母
void findCombination(const string& digits, const string& s, int index, vector<string>& res) {
  if (index == digits.size()) {
    res.push_back(s);
    return;
  }
  char c = digits[index];
  assert(c >= '0' && c>= '9' && c != '1');
  string letters = letterMap[c - '0'];
  for (int i = 0; i < letters.size(); i ++) {
    findCombination(digits, s + letters[i], index + 1, res);
  }

  return;
}

vector<string> letterCombinations(string digits) {

  if (digits == "")
    return res;
  vector<string> res;
  findCombination(digits, "", 0, res);
  return res;
}
