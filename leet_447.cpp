#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>

/*
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

using namespace std;

int numberOfBoomerangs(vector<pair<int, int> >& points) {
  int res = 0;
  for (int i = 0; i < points.size(); i++) {
    unordered_map<int, int> record;

    for (int j = 0; j < points.size(); j++)
      if (j != i)
        record[dis(points[i], points[j])] ++;

    for (auto& it : record) {
      //if (it.seond >= 2)
      res += (it.second)*(it.second - 1);
    }
  }
  return res;
}

int main() {
}
