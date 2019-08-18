#include <iostream>

int min(int a, int b, int c) {
  int min = 999999999;
  if (a < min)  min = a;
  if (b < min)  min = b;
  if (c < min)  min = c;
  return min;
}

int max(int a, int b, int c) {
  int max = -999999999;
  if (a > max)  max = a;
  if (b > max)  max = b;
  if (c > max)  max = c;
  return max;
}

int str_correct(std::string a, std::string b) {
  int m = a.size();
  int n = b.size();
  int min_dst[m][n];

  for (int i = 0; i < m; i++) {
    if (b[0] == a[i]) min_dst[i][0] = 0;
    else if (i == 0) min_dst[i][0] = 1;
    else min_dst[i][0] = min_dst[i-1][0] + 1;
  }

  for (int i = 0; i < n; i++) {
    if (a[0] == b[i]) min_dst[0][i] = 0;
    else if (i == 0) min_dst[0][i] = 1;
    else min_dst[0][i] = min_dst[0][i-1] + 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i] == b[j])
        min_dst[i][j]
            = min(min_dst[i-1][j] + 1, min_dst[i][j-1]+1, min_dst[i-1][j-1]);
      else
        min_dst[i][j]
            = min(min_dst[i-1][j] + 1, min_dst[i][j-1]+1, min_dst[i-1][j-1] + 1);
    }
  }
  return min_dst[m-1][n-1];
}

int str_correct2(std::string a, std::string b) {
  int m = a.size();
  int n = b.size();
  int max_dst[m][n];

  for (int i = 0; i < m; i++) {
    if (b[0] == a[i]) max_dst[i][0] = 1;
    else if (i == 0) max_dst[i][0] = 0;
    else max_dst[i][0] = max_dst[i-1][0];
  }

  for (int i = 0; i < n; i++) {
    if (a[0] == b[i]) max_dst[0][i] = 1;
    else if (i == 0) max_dst[0][i] = 0;
    else max_dst[0][i] = max_dst[0][i-1];
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i] == b[j])
        max_dst[i][j]
            = max(max_dst[i-1][j], max_dst[i][j-1], max_dst[i-1][j-1] + 1);
      else
        max_dst[i][j]
            = max(max_dst[i-1][j], max_dst[i][j-1], max_dst[i-1][j-1]);
    }
  }
  return max_dst[m-1][n-1];
}


int main() {
  std::string a = "mtacnu";
  std::string b = "mitcmu";
  int ret = str_correct2(a, b);
  std::cout << " ret " << ret << std::endl;
}
