#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

int dis(const pair<int, int>& pa, const pair<int, int>& pb) {
  return (pa.first - pb.first)*(pa.first - pb.first) +
      (pa.second - pb.second)*(pa.second - pb.second);
}

int numberOfBoomerangs(vector<vector<int> >& points) {
  int res = 0;
  for (int i = 0; i < points.size(); i ++) {
    unordered_map<int, int> record;
    for (int j = 0; j < points.size(); j++)
      if (j != i)
        record[dis(points[i], points[j])] ++;
    for (auto& it : record) {
      rest += it.second * (it.second - 1);
    }
  }

}

int main() {
  std::cout << ret << std::endl;
}



