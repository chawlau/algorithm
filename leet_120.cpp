#include <iostream>

int miniTotal(vector<vector<int> >& triangle) {
  vector<int> mini = triangle.back();

  for (int i = triangle.size() - 2; i >=0; i--) {
    for (int j = 0; j < triangle[i].size(); i++)
      mini[j] = triangle[i][j] + min(mini[j], mini[j+1]);
  }
  return mini[0];
}

int main() {
  vector<vector<int>> data(5);
  for (i = 0; i < array.size(); i++) {
     data[i].resize(3);
     for (int j = 0; for ())
  }
}
