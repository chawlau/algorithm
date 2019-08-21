#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;
struct TreeNode{ //树的结点
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode** root, int val) {
  if (*root == nullptr) {
    TreeNode* node = new TreeNode(val);
    (*root) = node;
    return;
  }

  if (val >= (*root)->val)
    insert(&(*root)->right, val);
  else
    insert(&(*root)->left, val);
}

vector<int> rightSideView(TreeNode* root);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  auto res = rightSideView(root);
  for (auto& it : res) {
      printf(" %d ", it);
    printf("\n");
  }
  return 0;
}

vector<int> rightSideView(TreeNode* root) {
  vector<int> res;
  if (!root) return res;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    res.push_back(q.back()->val);

    int end = q.size();
    while(end--) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  return res;
}
