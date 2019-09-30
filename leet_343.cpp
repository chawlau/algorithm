#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> memo;

//n进行分割，至少两部分
int max3(int a, int b, int c) {
  return max(a, max(b,c));
}

int helper(int n) {
  if (n == 1) return 1;

  if (memo[n] != -1)
    return memo[n];
  int res = -1;
  for (int i = 1; i <= n - 1; i++) {
    //i + (n - i)
    res = max3(res, i*(n - i), i * helper(n - i));
  }
  memo[n] = res;
  return res;
}


int integerBreak2(int n) {
  assert(n >= 2);
  memo = vector<int>(n + 1, -1);
  return helper(n);
}

int integerBreak(int n) {
  assert(n >= 2);
  memo = vector<int>(n + 1, -1);

  memo[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++)
      memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
  }

  return memo[n];
}


int integerBreak(int n) {
  assert(n >= 1);

  vector<int> memo(n+1, -1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i - 1; j++)
      mem[i] = max3(mem[i], j * (i - j), mem[i-j]*j);
  return mem[n];
}
