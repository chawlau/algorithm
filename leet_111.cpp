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

int minDepth(TreeNode* root);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  int res = minDepth(root);
  printf(" %d ", res);
  return 0;
}

int minDepth(TreeNode* root) {
  if (!root) return 0;

  if (!root->left) return 1 + minDepth(root->right);

  if (!root->right) return 1 + minDepth(root->left);

  return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

int minDepthII(TreeNode* root) {
  if (!root) return 0;

  queue<TreeNode*> q;
  q.push(root);

  int depth = 0;
  while (!q.empty()) {
    depth++;
    int size = q.size();
    while (size--) {
      TreeNode* node = q.front();
      q.pop();

      if (!node->left && !node->right) return depth;

      if (node->left) q.push(node->left);

      if (node->right) q.push(node->right);
    }
  }
  return -1;
}
