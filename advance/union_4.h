#ifndef INC_04_QUICK_FIND_UNIONFIND4_H
#define INC_04_QUICK_FIND_UNIONFIND4_H

#include <iostream>
#include <cassert>
using namespace std;

namespace UF4 {
class UnionFind {
 private:
  int count;
  int* parent;
  int* rank;

 public:
  UnionFind(int n) {
    count = n;
    parent = new int[count];
    rank = new int[count];
    for (int i = 0; i < n; i++){
      parent[i] = i;
      rank[i] = 1;
    }
  }

  ~UnionFind() {
    delete[] parent;
    delete[] rank;
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

    if (rank[pRoot] < rank[qRoot]) {
      parent[pRoot] = qRoot;
    } else if (rank[pRoot] > rank[qRoot]){
      parent[qRoot] = pRoot;
    } else {
      parent[qRoot] = pRoot;
      rank[pRoot] += 1;
    }
  }
};
}
#endif
