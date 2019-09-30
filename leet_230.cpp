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

int kthSmallest(TreeNode* root, int k);

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  return 0;
}

int countNodes(TreeNode* root) {
  return root == nullptr ? 0 : (1 + countNodes(root->left) + countNodes(root->right));
}

int kthSmallest(TreeNode* root, int k) {
  int cnt = countNodes(root->left);

  if (cnt == k - 1)
    return root->val;
  else if (cnt >= k)
    return kthSmallest(root->left, k);
  else if (cnt < k)
    return kthSmallest(root->right, k - 1 - cnt);

  return INT_MIN;
}

int kthSmallestII(TreeNode* root, int k) {
  stack<TreeNode*> st;
  TreeNode* p = root;
  while (!st.empty() || p) {
    if (p) {
      st.push(p);
      p = p->left;
    } else {
      TreeNode* node = st.top();
      st.pop();
      if (--k == 0) return node->val;
      p = node->right;
    }
  }

  return -1;
}
