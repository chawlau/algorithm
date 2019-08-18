#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

std::string sort_char_freq(std::string s) {
  std::map<char, int> freq;
  for (auto& c : s)
    freq[c]++;

  std::vector<std::string> bucket(s.size() + 1, "");

  for (auto& it : freq) {
    int n = it.second;
    char c = it.first;
    bucket[n].append(n, c);
  }

  std::string res;
  for (int i = s.size(); i >= 0; i--) {
    if (!bucket[i].empty())
      res.append(bucket[i]);
  }
  return res;
}

int main() {
  std::string s = "tree";
  std::string p = sort_char_freq(s);

  std::cout << "sort ret " << p << std::endl;
}



