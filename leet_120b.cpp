#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> mem;
int m;
int helper(vector<vector<int>>& triangle, int index) {
  if (index == 0) {
    cout << "help[0] " << triangle[0][0] << endl;
    return triangle[0][0];
  }

  int res = INT_MAX;
  int n = triangle[index].size();
  for (int i = 0; i < n && i + 1 < n; i++) {
    int next = triangle[index][i + 1];
    res = min(res, helper(triangle, index - 1) + min(triangle[index][i], next));
    cout << "help:" << index << " val " << triangle[index][i]
        << " next " << next << " res " << res << endl;
  }
  cout << "help:" << index << " res " << res << endl;
  return res;
}

int minimumTotal(vector<vector<int> >& triangle) {
  int res = 0;
  m = triangle.size();
  if (m == 0)
    return 0;
  res = helper(triangle, m - 1);
  return res;
}

int main() {
  //vector<vector<int>> data = {{2},{3,4},{6,5,7},{4,1,8,3}};
  vector<vector<int>> data = {{-1},{2,3},{1,-1, -3}};

  int ret = minimumTotal(data);
  cout << "ret " << ret << endl;
}

