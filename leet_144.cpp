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

struct Command {
  string s;
  TreeNode* node;
  Command(string s, TreeNode* node) : s(s), node(node) {}
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

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;

  if (!root) return res;

  stack<Command> stack;
  stack.push(Command("go", root));

  while (!stack.empty()) {
    Command command = stack.top();
    stack.pop();

    if (command.s == "print")
      res.push_back(command.node->val);
    else {
      assert(command.s == "go");
      if (command.node->right)
        stack.push(Command("go", command.node->right));

      if (command.node->left)
        stack.push(Command("go", command.node->left));

      stack.push(Command("print", command.node));
    }
  }
  return res;
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;

  if (!root) return res;

  stack<Command> stack;
  stack.push(Command("go", root));

  while (!stack.empty()) {
    Command command = stack.top();
    stack.pop();

    if (command.s == "print")
      res.push_back(command.node->val);
    else {
      assert(command.s == "go");
      if (command.node->right)
        stack.push(Command("go", command.node->right));

      if (command.node->left)
        stack.push(Command("go", command.node->left));

      stack.push(Command("print", command.node));
    }
  }
  return res;
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;

  if (!root) return res;

  stack<Command> stack;
  stack.push(Command("go", root));

  while (!stack.empty()) {

    Command command = stack.top();
    stack.pop();

    if (command.s == "print")
      res.push_back(command.node->val);
    else {
      assert(command.s == "go");

      if (command.node->right)
        stack.push(Command("go", command.node->right));

      stack.push(Command("print", command.node));

      if (command.node->left)
        stack.push(Command("go", command.node->left));
    }
  }
  return res;
}


void level_order(TreeNode* root) {
  std::queue<TreeNode*> que;
  if (root == NULL) return;

  que.push(root);
  int level = 0;
  int to_be_print = 1;
  while (!que.empty()) {
    TreeNode* node = que.front();
    printf(" %d ", node->val);

    if (node->left != NULL) {
      que.push(node->left);
      level++;
    }

    if (node->right != NULL) {
      que.push(node->right);
      level++;
    }

    que.pop();
    to_be_print --;

    if (to_be_print == 0) {
      printf("\n");
      to_be_print = level;
      level = 0;
    }
  }
  printf(" level order finish \n");
}

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;

  if (!root) return res;

  stack<Command> stack;
  stack.push(Command("go", root));

  while (!stack.empty()) {
    Command command = stack.top();
    stack.pop();

    if (command.s == "print")
      res.push_back(command.node->val);
    else {
      assert(command.s == "go");
      stack.push(Command("print", command.node));

      if (command.node->right)
        stack.push(Command("go", command.node->right));

      if (command.node->left)
        stack.push(Command("go", command.node->left));
    }
  }
  return res;
}

int main()
{
  TreeNode* root = nullptr;//创建一个空树
  vector<int> data = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (auto& it : data)//输入n个数并创建这个树
    insert(&root, it);

  level_order(root);
  auto res = postorderTraversal(root);
  for (auto& it : res) {
    printf(" %d ", it);
  }
  printf("\n");
  return 0;
}

