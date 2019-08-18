#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
  int m1[256] = {0}, m2[256] = {0}, n = s.size();

  for (int i = 0; i < n; i++) {
    if (m1[s[i]] != m2[t[i]]) return false;
    m1[s[i]] = m2[t[i]] = i;
  }
  return true;
}

int main() {
  bool ret  = isIsomorphic("eag", "aed");

  std::cout << "sort ret " << ret << std::endl;
}



