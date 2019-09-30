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

bool hasPathSum(TreeNode* root, int sum);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  auto res = levelOrder(root);
  for (auto& it : res) {
    for (auto& it1 : it) {
      printf(" %d ", it1);
    }
    printf("\n");
  }
  return 0;
}


bool hasPathSum(TreeNode* root, int sum) {

  if (!root) return false;
  if(!root->left && !root->right) return root->val == sum;

  /*
      5
       \
        8
       / \
      13  4
    符合左子树为空的条件，但是不满足题意*/
  if (hasPathSum(root->left, sum - root->val)) return true;

  if (hasPathSum(root->right, sum - root->val)) return true;

  return false;
}
