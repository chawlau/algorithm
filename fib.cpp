#include <iostream>
#include <vector>
using namespace std;

int num = 0;

vector<int> memo;
int fib(int n) {
  num ++;

  if (n == 0) return 0;
  if (n == 1) return 1;

  if (memo[n] == -1)
    memo[n] = fib(n - 1) + fib(n - 2);

  return memo[n];
}

int fib(int n) {
  vector<int> memo(n + 1, -1);
  mem[0] = 0;
  mem[1] = 1;
  for (int i = 2; i <= n; i++)
    memo[i] = memo[i - 1] + mem[i - 2];
  return memo[n];
}

int main() {
  int n = 40;

  memo = vector<int>(n + 1, -1);
  int ret = fib(n);
  cout << "ret " << ret;
}
