#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

typedef struct _Node {
  int val;
  struct _Node* next;
}Node;

void insert_node(Node** head, int val) {
  Node* node = (Node*)calloc(1, sizeof(Node));
  node->val = val;
  node->next = *head;
  *head = node;
}

void print_node(Node* head) {
  Node* temp = head;
  while (temp) {
    printf(" %d ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

Node* deleteDuplicate(Node* head) {
  if (!head) return head;

  Node* p = head;
  while (p->next) {
    if (p->val != p->next->val)
      p = p->next;
    else
      p->next = p->next->next;
  }
  return head;
}

int main() {
  Node* head = NULL;
  insert_node(&head, 6);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  insert_node(&head, 1);
  insert_node(&head, 1);
  print_node(head);
  Node* ret = deleteDuplicate(head);
  print_node(ret);
}
