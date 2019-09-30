#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

int numSquares(int n);

int main()
{
  int ret = numSquares(12);
  printf(" %d ", ret);
  return 0;
}

int numSquares(int n) {
  vector<bool> visited(n + 1, false);
  visited[n] = true;
  queue<pair<int, int>> q;

  q.push(make_pair(n, 0));

  int ret = 0;
  while (!q.empty()) {
    int num = q.front().first;
    int step = q.front().second;
    q.pop();

    for (int i = 1; ; i++) {
      int a = num - i * i;

      if (a < 0) break;

      if (a == 0) {
        ret = step + 1;
        return ret;
      }

      if (!visited[a]) {
        visited[a] = true;
        q.push(make_pair(a, step + 1));
      }
    }
  }
  return ret;
}

int numSquares(int n) {
  if (n == 0) return 0;
  vector<int> res(n + 1, n);
  res[1] = 1;

  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= sqrt(i); j++)
      res[i] = min(res, 1 + res[i - j*j]);

  return res[n];
}
