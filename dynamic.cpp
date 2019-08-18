#include <climits>
#include <iostream>

int max = INT_MIN;
bool mem[5][10];


//i 是已经遍历的物品, cw到目前为止累加的总重量
int knpack(int weight[], int n, int w) {
  bool state[5][10] = {false};

  state[0][0] = true;
  if (weight[0] <= w) state[0][weight[0]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= w; j++) {
      if (state[i-1][j] == true)
        state[i][j] = state[i - 1][j];
    }

    for (int j = 0; j <= w - weight[i]; j++) {
      if (state[i-1][j] == true)
        state[i][j + weight[i]] = true;
    }
  }

  for (int i = w; i >= 0; i--) {
    if (state[n - 1][i] == true) {
      max = i;
      return max;
    }
  }
}

int knpack2(int weight[], int n, int w) {
  bool state[10];
  state[0] = true;

  if (weight[0] <= w) state[weight[0]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = w - weight[i]; j >= 0; j--) {
      if (state[j] == true) state[j + weight[i]] = true;
    }
  }

  for (int i = w; i >= 0; i--) {
    if (state[i] == true) {
      max = i;
      return max;
    }
  }
}

int knpack3(int item[], int val[], int n, int w) {
  int state[n][w+1];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= w; j++) {
      state[i][j] = -1;
    }
  }

  state[0][0] = 0;
  if (item[0] <= w) state[0][item[0]] = val[0];

  for (int i = 1; i < n ; i++) {
    for (int j = 0; j <= w; j++) {
      if (state[i - 1][j] >= 0) state[i][j] = state[i - 1][j];
    }

    for (int j = 0; j <= w - item[i]; j++) {
      if (state[i - 1][j] >= 0) {
        int v = state[i - 1][j] + val[i];
        if (v > max)
          state[i][j + item[i]] = v;
      }
    }
  }

  max = -1;
  for (int i = w; i >= 0; i--) {
    if (state[n - 1][i] > max)
      max = state[n - 1][i];
  }
  return max;
}

int main() {
  int n = 5;
  int w = 9;
  int items[] = {2, 2, 4, 6, 3};
  int value[] = {3, 4, 8, 9, 6};
  int ret = knpack3(items, value, n, w);
  std::cout << "max weight " << ret;
}
