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

int sumOfLeftLeaves(TreeNode* root);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  auto res = sumOfLeftLeaves(root);
  printf(" %d ", res);
  return 0;
}

int sumOfLeftLeaves(TreeNode* root) {
  if (!root) return 0;

  if (root->left && !root->left->left && !root->left->right) {
    return root->left->val + sumOfLeftLeaves(root->left);
  }
  return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);

  return 0;
}
