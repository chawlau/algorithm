#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

std::vector<int> find_anagrams(std::string s, std::string p) {
  std::vector<int> pv(26, 0), sv(26, 0), res;

  if (s.size() < p.size()) return res;

  for (int i = 0; i < p.size(); i++) {
    pv[p[i] - 'a']++;
    sv[s[i] - 'a']++;
  }

  if (pv == sv) res.push_back(0);

  for (int i = p.size(); i < s.size(); i++) {
    sv[s[i] - 'a']++;
  }
}
int main() {
  std::string s = "abcdabcdefbb";
  int ret = longest_sub_str_len(s);
  std::cout << "min sub len " << ret << std::endl;
}



