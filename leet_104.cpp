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

int maxDepth(TreeNode* root);

int maxDepthII(TreeNode *root);
int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  int ret = maxDepthII(root);
  printf(" %d ", ret);
  return 0;
}


int maxDepth(TreeNode* root) {
  if (!root) return 0;

  int leftMaxDepth = maxDepth(root->left);

  int rightMaxDepth = maxDepth(root->right);

  return max(leftMaxDepth, rightMaxDepth) + 1;
}

int maxDepthII(TreeNode *root)
{
  if(root == NULL)
    return 0;

  int res = 0;
  queue<TreeNode *> q;
  q.push(root);
  while(!q.empty())
  {
    ++ res;
    for(int i = 0, n = q.size(); i < n; ++ i)
    {
      TreeNode *p = q.front();
      q.pop();

      if(p -> left != NULL)
        q.push(p -> left);
      if(p -> right != NULL)
        q.push(p -> right);
    }
  }
  return res;
}
