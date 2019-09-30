#include <iostream>
#include <vector>

vector<vector<int>> memo;
int helper(const vector<int>& w, const vector<int>& v, int index, int c) {
  if (index < 0 || c <= 0)
    return 0;

  if (memo[index][c] != -1)
    return memo[index][c];
  int res = helper(w, v, index - 1, c);

  if (c >= w[index])
    res = max(res, v[index] + helper(w, v, index - 1, c - w[index]));
  memo[index][c] = res;
  return res;
}

int knapsack01(const vector<int>& w, const vector<int>& v, int C) {

  int n = w.size();
  memo = vector<vector<int>>(n, vector<int>(C+1, -1));
  return helper(w, v, n - 1, C);
}


//v1
int knapsack01II(const vector<int>& w, const vector<int>& v, int C) {
  assert(w.size() == v.size())
  int n = w.size();
  if (n == 0)
    return 0;
  memo = vector<vector<int>>(n, vector<int>(C+1, -1));

  for (int j = 0; j <= C; j++)
    memo[0][j] = (j > w[0] ? v[0] : 0);

  for (int i = 1; i < n; i++)
    for (int j = 0; j <= C; j++) {
      memo[i][j] = memo[i-1][j];
      if (j >= w[i])
        memo[i][j] = max(memo[i][j], v[i] + memo[i-1][j-w[i]]);
    }
  return memo[n-1][C];
}

//v1.5
int knapsack01II(const vector<int>& w, const vector<int>& v, int C) {
  assert(w.size() == v.size())
  int n = w.size();
  if (n == 0)
    return 0;
  memo = vector<vector<int>>(2, vector<int>(C+1, -1));

  for (int j = 0; j <= C; j++)
    memo[0][j] = (j > w[0] ? v[0] : 0);

  for (int i = 1; i < n; i++)
    for (int j = 0; j <= C; j++) {
      memo[i%2][j] = memo[(i-1)%2][j];
      if (j >= w[i])
        memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]]);
    }
  return memo[(n-1)%2][C];
}


//v2
int knapsack01II(const vector<int>& w, const vector<int>& v, int C) {
  assert(w.size() == v.size())
  int n = w.size();
  if (n == 0)
    return 0;
  vector<int> memo(C+1, -1);

  for (int j = 0; j <= C; j++)
    memo[j] = (j > w[0] ? v[0] : 0);

  for (int i = 1; i < n; i++)
    for (int j = C; j >= w[i]; j--)
      memo[j] = max(memo[j], v[i] + memo[j-w[i]]);
  return memo[C];
}
