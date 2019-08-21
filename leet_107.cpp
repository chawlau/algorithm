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

vector<vector<int>> levelOrderII(TreeNode* root);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  auto res = levelOrderII(root);
  for (auto& it : res) {
    for (auto& it1 : it) {
      printf(" %d ", it1);
    }
    printf("\n");
  }
  return 0;
}

vector<vector<int>> levelOrderII(TreeNode* root) {
  vector<vector<int>> res;
  if (!root) return res;

  queue<pair<TreeNode*, int>> q;
  q.push(make_pair(root, 0));

  while (!q.empty()) {
    TreeNode* node = q.front().first;
    const int level = q.front().second;
    q.pop();

    if (level == res.size())
      res.insert(res.begin(), vector<int>());

    res.begin()->push_back(node->val);

    if (node->left)
      q.push(make_pair(node->left, level + 1));
    if (node->right)
      q.push(make_pair(node->right, level + 1));
  }

  return res;
}
