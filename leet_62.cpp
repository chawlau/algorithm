#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int m, n;
vector<vector<int>> mem;
int d[2][2] = {{1,0}, {0,1}};
int inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

int helper(vector<vector<int>>& grid, int x, int y) {
  if (x == m - 1 && y == n - 1)
    return 1;

  int res = 0;
  for (int i = 0; i < 2; i++) {
    int newx = x + d[i][0];
    int newy = y + d[i][1];
    if (inArea(newx, newy)) {
      res += helper(grid, newx, newy);
    }
  }

  return res;
}

int uniquePaths(int m, int n) {
  if (m = 0 || n == 0) return 1;
  //mem = vector<vector<bool>>(m, vector<bool>(n, false));
  int res = helper(grid, 0, 0);
  return res;
}
