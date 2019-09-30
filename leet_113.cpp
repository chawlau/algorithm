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

vector<vector<int> > pathSum(TreeNode *root, int sum);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  return 0;
}


void findPath(TreeNode *root, int sum, vector<vector<int>>& res,
                             vector<int>& path) {
  if (!root) return;


  path.push_back(root->val);
  if (root->val == sum && !root->left && !root->right) {
    res.push_back(path);
  }

  findPath(root->left, sum - root->val, res, path);
  findPath(root->right, sum - root->val, res, path);

  path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
  vector<vector<int>> res;
  vector<int> path;
  findPath(root, sum, res, path);
  return res;
}
