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
    printf("node val %d ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

Node* reverse(Node* head) {
  Node* pre = NULL;
  Node* next = NULL;
  while (head) {
    next = head->next;
    head->next = pre;
    pre = head;
    head= next;
  }
  return pre;
}

Node* removeElements(Node* head, int val) {
  Node dumy;
  dumy.next = head;
  Node* cur = &dumy;
  while (!cur->next) {
    if (cur->next->val == val) {
      Node* node = cur->next;
      cur->next = node->next;
    } else {
      cur = cur->next;
    }
  }
  return dumy.next;
}

int main() {
  Node* head = NULL;
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  print_node(head);
  Node* ret = reverse(head);
  print_node(ret);
}
