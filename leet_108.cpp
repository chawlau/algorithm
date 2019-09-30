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

TreeNode* sortedArrayToBST(vector<int>& nums);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  return 0;
}


TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
  if (start > end) return nullptr;

  int mid = (start + end) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = sortedArrayToBST(nums, start, mid - 1);
  root->right = sortedArrayToBST(nums, mid + 1, end);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return sortedArrayToBST(nums, 0, nums.size() - 1);
}
