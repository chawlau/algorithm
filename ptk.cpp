#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int resTotal(vector<vector<int> >& triangle) {

  vector<int> res = triangle[triangle.size() - 1];
  for (int i = triangle.size() - 2; i > = 0; i--) {
    for (int j = 0; j < triangle[i].size(); j++) {
      res[j] = triangle[i][j] + min(res[j], res[j+1]);
    }
  }
  return res[];
}


vector<vector<int>> mem;
int m, n;
int helper(vector<vector<int>>& triangle, int x, int y) {
  if (x >= triangle.size() || y >= triangle[x].size()) return 0;

  if (mem[x][y] != INT_MAX)
    return mem[x][y];
  int res = triangle[x][y];
  res = min(res + helper(triangle, x + 1, y), res + helper(triangle, x + 1, y + 1));
  mem[x][y] = res;
  return res;
}

int helper2(vector<vector<int>>& triangle, int x, int y) {
  if (x < 0 || y < 0) return 0;
  if (x == 0 && y == 0) return triangle[x][y];

  if (mem[x][y] != INT_MAX)
    return mem[x][y];
  int res = triangle[x][y];
  res = min(res + helper2(triangle, x , y - 1), res + helper(triangle, x - 1, y + 1));
  mem[x][y] = res;
  return res;
}


int minimumTotal(vector<vector<int> >& triangle) {
  int res = 0;
  m = triangle.size();
  if (m == 0)
    return 0;

  n = triangle.back().size();

  int res = INT_MAX;
  mem = vector<vector<int>>(m, vector<int>(n, INT_MAX));
  for (int i = 0; i < n; i++)
    res = min(res, helper2(triangle, m - 1, i));
  return res;
}

int resmumTotal(vector<vector<int>>& triangle) {
  int res = 0;
  m = triangle.size();
  n = triangle[m - 1].size();
  if (m == 0) return res;

  mem = vector<vector<int>>(m, vector<int>(n, INT_MAX));
  res = helper(triangle, 0, 0);
  return res;
}

int main() {
  vector<vector<int>> matrix = {{2},{3,4},{6,5,7},{4,1,8,3}};
  int res = resTotal(matrix);
  cout << res;
}
