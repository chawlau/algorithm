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
  if (mem[x][y] != -1)
    return mem[x][y];

  int res = INT_MAX;
  for (int i = 0; i < 2; i++) {
    int newx = x + d[i][0];
    int newy = y + d[i][1];
    if (inArea(newx, newy)) {
      res = min(res, grid[x][y] + helper(grid, newx, newy));
    }
  }

//v1
  mem[x][y] = res;
  return res;
}

int minPathSum(vector<vector<int>>& grid) {
  m = grid.size();
  if (m == 0)
    return 0;
  n = grid[0].size();

  mem = vector<vector<int>>(m, vector<int>(n, -1));
  mem[m-1][n-1] = grid[m-1][n-1];
  int res = helper(grid, 0, 0);
  return res;
}

int minPathSumII(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));

  for (int i = 1; i < m; i++)
    sum[i][0] += sum[i-1][0] + grid[i][0];

  for (int i = 1; i < n; i++)
    sum[0][i] += sum[0][i-1] + grid[0][i];

  for (int i = 1; i < m; i++)
    for (int j = 1; j < n;j++)
      sum[i][j] = grid[i][j] + min(sum[i][j-1], sum[i-1][j]);
  return sum[m-1][n-1];
}
