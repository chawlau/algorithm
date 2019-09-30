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

int pathSum(TreeNode* root, int sum);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  auto res = countNodes(root);
  cout << res << endl;
  return 0;
}

int findPath(TreeNode* node, int num) {
  if (!root) return 0;

  int res = 0;

  //需要继续向下遍历,考虑负数的情况
  if (node->val == num)
    res += 1;

  res += findPath(node->left, num - node->val);
  res += findPath(node->right, num - node->val);
  return res;
}

int pathSum(TreeNode* root, int sum) {
  if (!root) return 0;

  int res = findPath(root, sum);

  res += pathSum(root->left, sum);
  res += pathSum(root->right, sum);
}
