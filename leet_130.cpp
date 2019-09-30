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

bool inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

void helper(vector<vector<char>>& board, int x, int y) {
  /*
  if (!inArea(x, y)) return;

  if (board[x][y] == 'O') board[x][y] == '*';

  for (int i = 0; i < 4; i++) {
    int newx = x + d[i][0];
    int newy = y + d[i][1];

    if (inArea(newx, newy) && board[newx][newy] == 'O')
      if (x > 1 || x < m - 2 || y > 1 || y < n - 2)
        helper(board, newx, newy);
  }
  */
  if (x < 0 || x > m - 1 || y <0 || y > n - 1)
    return;
  if (board[x][y] == 'O')
    board[x][y] = '*';
  if (x > 1 && board[x-1][y] == 'O')
    helper(board, x-1, y);
  if (x < m - 2 && board[x+1][y] == 'O')
    helper(board, x+1, y);
  if (y > 1 && board[x][y-1] == 'O')
    helper(board, x, y-1);
  if (y < n - 2 && board[x][y+1] == 'O' )
    helper(board, x, y+1);

  return;
}

void solve(vector<vector<char>>& board) {
  m = board.size();
  if (m == 0)
    return;
  n = board[0].size();

  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O')
      helper(board, i, 0);
    if (board[i][n-1] == 'O')
      helper(board, i, n-1);
  }

  for (int j = 0; j < n; j++) {
    if (board[0][j] == 'O')
      helper(board, 0, j);
    if (board[m-1][j] == 'O')
      helper(board, m-1, j);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '*')
        board[i][j] = 'O';
      else
        board[i][j] = 'X';
    }
  }
}
