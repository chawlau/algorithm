#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cassert>

using namespace std;

vector<vector<string>> res;
vector<bool> col, dia1, dia2;

vector<string> generateBoard(int n, vector<int>& row) {
  assert(row.size() == n);
  vector<string> board(n, string(n, '.'));
  for (int i = 0; i < n; i++)
    board[i][row[i]] = 'Q';
  return board;
}

//n皇后摆放在index行的皇后位置
void putQueen(int n, int index, vector<int>& row) {

  if (index == n) {
    res.push_back(generateBoard(n, row));
    return;
  }

  for (int i = 0; i < n; i++)
    if (!col[i] && !dia1[index+i] && !dia2[index-i+n-1]) {
      row.push_back(i);
      col[i] = true;
      dia1[index+i] = true;
      dia2[index-i+n-1] = true;
      putQueen(n, index + 1, row);
      col[i] = false;
      dia1[index+i] = false;
      dia2[index-i+n-1] = false;
      row.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
  res.clear();

  col = vector<bool>(n, false);
  dia1 = vector<bool>(2 * n - 1, false);
  dia2 = vector<bool>(2 * n - 1, false);
  vector<int> row;
  putQueen(n, 0, row);
  return res;
}

int main() {
  int n = 8;
  vector<vector<string>> res = solveNQueens(n);
  for (auto& i : res) {
    for (auto& j : i) {
      cout << j << endl;
    }
    cout << endl;
  }
}
