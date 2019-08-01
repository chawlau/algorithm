#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>

using namespace std;

string minWindow(string s, string t) {
  vector<int> map(128, 0);
  for(auto c : t) map[c]++;

  int d = 9999999;
  int counter = t.size(), begin = 0, end = 0, head = 0;

  while (end < s.size()){
    if(map[s[end++]]-- > 0)
      counter--; //in t

    while(counter == 0){ //valid
      if(end - begin < d)
        d = end - (head = begin);

      if(map[s[begin++]]++ == 0)
        counter ++;  //make it invalid
    }
  }

  return d == 9999999? "":s.substr(head, d);
}

int main() {
  std::string s = "ADOBECODEBANCBAC";
  std::string p = "ABC";
  std::string ret = minWindow(s, p);

  std::cout << ret << std::endl;
}



