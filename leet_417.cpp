#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};

int m, n;

vector<vector<bool>> pv;
vector<vector<bool>> av;

int inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

void helper(vector<vector<int>>& matrix, vector<vector<bool>> visited, int x, int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int newx = x + d[i][0];
    int newy = y + d[i][1];

    if (inArea(newx, newy) && !visited[newx][newy]
        && matrix[newx][newy] >= matrix[x][y])
      helper(matrix, visited, newx, newy);
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
  vector<vector<int>> res;

  m = matrix.size();
  if (m == 0)
    return res;
  n = matrix[0].size();

  pv = vector<vector<bool>>(m, vector<bool>(n, false));
  av = vector<vector<bool>>(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    helper(matrix, pv, i, 0);
    helper(matrix, av, i, n - 1);
  }

  for (int j = 0; j < n; j++) {
    helper(matrix, pv, 0, j);
    helper(matrix, av, m - 1, j);
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (pv[i][j] && av[i][j]) {
        vector<int> it(i, j);
        res.push_back(it);
      }
  return res;
}
