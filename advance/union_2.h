#ifndef INC_02_QUICK_FIND_UNIONFIND2_H
#define INC_02_QUICK_FIND_UNIONFIND2_H

#include <iostream>
#include <cassert>
using namespace std;

namespace UF2 {
class UnionFind {
 private:
  int count;
  int* parent;

 public:
  UnionFind(int n) {
    count = n;
    parent = new int[count];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  ~UnionFind() {
    delete[] parent;
  }

  int find (int p) {
    assert(p >= 0 && p < count);
    while (p != parent[p])
      p = parent[p];
    return p;
  }

  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }

  void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot) return;

    parent[pRoot] = qRoot;
  }
};
}
#endif
