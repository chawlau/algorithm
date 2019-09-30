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

vector<string> binaryTreePaths(TreeNode* root);
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

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> res;
  if (!root) return res;

  if (!root->left && !root->right) {
    res.push_back(to_string(root->val));
  }

  vector<string> leftS = binaryTreePaths(root->left);
  for (auto& it : leftS)
    res.push_back(to_string(root->val) + "->" + it);

  vector<string> rightS = binaryTreePaths(root->right);
  for (auto& it : rightS)
    res.push_back(to_string(root->val) + "->" + it);

  return res;
}
