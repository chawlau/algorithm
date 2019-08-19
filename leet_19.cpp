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

ListNode* removeNthFromEnd(ListNode* head, int n);

int main() {
  ListNode* head1 = nullptr;
  insert_node(&head1, 6);
  insert_node(&head1, 5);
  insert_node(&head1, 4);
  insert_node(&head1, 3);
  insert_node(&head1, 2);
  insert_node(&head1, 1);
  print_node(head1);

  ListNode* ret = removeNthFromEnd(head1, 2);
  print_node(ret);
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  assert(n >= 0);
  ListNode node(0);
  node.next = head;

  ListNode* p = &node;
  ListNode* q = &node;

  for (int i = 0; i < n + 1; i++) {
    assert(q);
    q = q->next;
  }

  while (q) {
    p = p->next;
    q = q->next;
  }

  ListNode* delNode = p->next;
  p->next = delNode->next;
  delete delNode;

  return node.next;
}

