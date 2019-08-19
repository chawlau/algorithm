#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int val_) : val(val_), next(nullptr) {}
};

void insert_node(ListNode** head, int val) {
  ListNode* node = new ListNode(0);
  node->next = *head;
  node->val = val;
  *head = node;
}

void print_node(ListNode* head) {
  while (head) {
    printf(" %d ", head->val);
    head = head->next;
  }
  printf("\n");
}

void deleteNode(ListNode* head);
int main() {
  ListNode* head1 = nullptr;
  insert_node(&head1, 6);
  insert_node(&head1, 5);
  insert_node(&head1, 4);
  insert_node(&head1, 3);
  insert_node(&head1, 2);
  insert_node(&head1, 1);

  print_node(head1);
}

void deleteNode(ListNode* node) {
  if (!node) return;
  if (!node->next) {
    delete node;
    node = nullptr;
    return;
  }

  node->val = node->next->val;
  ListNode* delNode = node->next;
  node->next = delNode->next;
  delete delNode;
  return;
}

