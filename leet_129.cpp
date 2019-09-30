#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>

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

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  return 0;
}

int sumR(TreeNode* root, int sum) {
  if (!root) return 0;

  int val = 0;
  if (!root->left && !root->right)
    return 10 * sum + root->val;

  if (root->left)
    val +=sumR(root->left, 10 * sum + root->val);
  if (root->right)
    val +=sumR(root->right, 10 * sum + root->val);
  return val;
}

int sumNumbers(TreeNode* root) {
  if (!root) return 0;
  return sumR(root, 0);
}
