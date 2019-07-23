#include<stdio.h>
#include<stdlib.h>
#include <queue>
typedef struct _Node{ //树的结点
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

void insert(Node** root, int value) {
  if (*root == NULL) {
    Node* node=(Node*)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    (*root) = node;
    return;
  }

  if (value >= (*root)->data) {
    insert(&(*root)->right, value);
  } else {
    insert(&(*root)->left, value);
  }
}

void inorder(Node* node)//树的中序遍历
{
  if (node != NULL)
  {
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
  }
}

void level_order(Node* root) {
  std::queue<Node*> que;
  if (root == NULL) return;

  que.push(root);
  int level = 0;
  int to_be_print = 1;
  while (!que.empty()) {
    Node* node = que.front();
    printf(" %d ", node->data);

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

int main()
{
  Node* root = NULL;//创建一个空树
  int i, data[10] = {7, 4, 9, 2, 6, 8, 10, 1, 3, 5};
  for (i = 0; i < 10; i++)//输入n个数并创建这个树
  {
    insert(&root, data[i]);
  }
  inorder(root);
  return 0;
}

