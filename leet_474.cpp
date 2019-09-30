#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

  for (auto& str : strs) {
    int ones = count(str.begin(), str.end(), '1');
    int zeros = str.size() - ones;

    for (int i = m; i >= zeros; i--)
      for (int j = n; j >= ones; j--)
        dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
  }

  return dp[m][n];
}

int main() {
  vector<string> str = {"10", "0001", "111001", "1", "0"};
  int ret = findMaxForm(str, 5, 3);
  cout << "ret " << ret << endl;
}
