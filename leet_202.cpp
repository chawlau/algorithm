#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

bool wordPattern(string p, string s) {
  std::map<char, int> pd;
  std::map<std::string, int> sd;
  std::istringstream in(s);

  int i = 0, n = p.size();
  for (std::string word; in >> word; ++i) {
    if (i == n || pd[p[i]] != sd[word]) return false;
    pd[p[i]] = sd[word] = i + 1;
  }
  return i == n;
}

int main() {
  bool ret  = wordPattern("abbx", "dog cat cat dog");

  std::cout << "sort ret " << ret << std::endl;
}



