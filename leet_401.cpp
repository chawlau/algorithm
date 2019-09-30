#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> res;

void helper(vector<int>& chart,int&num,int curr,int idx,int hour,int min){
  if(hour>11||min>59) return;
  if(curr==num){
    string tmp=to_string(hour)+":"+((min<10)?"0":"")+to_string(min);
    res.push_back(tmp);
    return;
  }
  for(int i=idx;i<chart.size();i++){
    if(i<4)
      helper(chart,num,curr+1,i+1,hour+chart[i],min);
    else
      helper(chart,num,curr+1,i+1,hour,min+chart[i]);
  }
}

vector<string> readBinaryWatch(int num) {
  vector<int> chart({1,2,4,8,1,2,4,8,16,32});
  helper(chart,num,0,0,0,0);
  return res;
}

int main() {
  auto res = readBinaryWatch(9);
}

