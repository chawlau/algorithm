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

TreeNode* deleteNode(TreeNode* root, int key);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  return 0;
}

TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root) return nullptr;

  if (root->val == key) {
    if (!root->right) {
      TreeNode* left = root->left;
      delete root;
      return left;
    } else {
      TreeNode* node = root->right;
      while (node->left)
        node = node->left;
      swap(node->val, root->val);
    }
  }
  root->left = deleteNode(root->left, key);
  root->right = deleteNode(root->right, key);
  return root;
}
