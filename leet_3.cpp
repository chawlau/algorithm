#include <iostream>
#include <vector>
#include <cassert>

int longest_sub_str_len(std::string s) {
  int freq[256] = {0};

  int l = 0, r = -1;//windows[l, r]
  int res = 0;

  while (l < s.size()) {
    if (freq[s[r+1]] == 0 && r + 1 < s.size())
      freq[s[++r]] ++;
    else
      freq[s[l++]] -- ;

    res = res > r - l + 1 ? res : r - l + 1;
  }
  return res;
}

int main() {
  std::string s = "abcdabcdefbb";
  int ret = longest_sub_str_len(s);
  std::cout << "min sub len " << ret << std::endl;
}



