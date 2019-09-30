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

vector<vector<bool>> visisted;

int inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}

bool helper(vector<vector<char>>& board, string word, int idx, int startx, int starty) {
  if (index == word.size() - 1)
    return board[startx][starty] == word[index];

  if (board[startx][starty] == word[index]) {
    visited[startx][starty] = true;
    for (int i = 0; i < 4; i++) {
      int newx = startx + d[i][0];
      int newy = starty + d[i][1];

      if (inArea(newx, newy) && !visted[newx][newy])
        if (helper(board, word, index + 1, newx, newy))
          return true;
    }
    visited[startx][starty] = false;
  }
}

bool exist(vector<vector<char>>& board, string word) {
  m = board.size();
  n = board[0].size();
  visited = vector<vector<bool>>(m, vector<bool>(n, false));
  for (int i = 0; i < board.size(); i ++)
    for (int j = 0; j < board[i].size(); j++)
      if helper(board, word, 0, i, j)
        return true;

  return false;
}
