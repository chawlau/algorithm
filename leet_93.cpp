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

class Solution {
 private:
  void helper(string s, vector<string>& p,vector<string>& res,int idx){
    if (idx == 4 && p.size() == 4) {
      string tmp;
      tmp += (p[0]+".");
      tmp += (p[1]+".");
      tmp += (p[2]+".");
      tmp += (p[3]);
      res.push_back(tmp);
      return;
    } else if(p.size()==4 && idx!=0) return;
    else if(p.size()!=4 && idx==0) return;

    for(int i=1;i<=3 && i<=length;i++){
      string ts = s.substr(s.length()-length,i);
      int num = stoi(ts);
      if(num>=0 && num<=255 && (i==1 || ts[0]!='0')){
        p.push_back(ts);
        helper(s, p, res, idx + 1);
        p.pop_back();
      }
    }
  }
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> p;
    helper(s, p, res, 0);
    return res;
  }
};
