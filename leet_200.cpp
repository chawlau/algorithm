#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
//顺时针或者逆时针
int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

int m, n;

vector<vector<bool>> visited;

bool inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

void helper(vector<vector<char>>& grid, int x, int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int newx = x + d[i][0];
    int newy = y + d[i][1];

    if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
      helper(grid, newx, newy);
  }

  return;
}

int numIslands(vector<vector<char>>& grid) {
  m = grid.size();
  if (m == 0)
    return 0;
  n = grid[0].size();

  visited = vector<vector<bool>>(m, vector<bool>(n, false));

  int res = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == '1' && !visited[i][j]) {
        res ++;
        helper(grid, i, j);
      }
  return res;
}
