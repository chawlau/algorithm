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


ListNode* swapParis(ListNode* head);

int main() {
  ListNode* head1 = nullptr;
  insert_node(&head1, 6);
  insert_node(&head1, 5);
  insert_node(&head1, 4);
  insert_node(&head1, 3);
  insert_node(&head1, 2);
  insert_node(&head1, 1);

  print_node(head1);
  ListNode* ret = swapParis(head1);
  print_node(ret);
}

ListNode* swapParis(ListNode* head) {
  ListNode node(0), *p = &node;
  node.next = head;

  while (p->next && p->next->next) {
    ListNode* node1 = p->next;
    ListNode* node2 = p->next->next;

    ListNode* next = node2->next;
    node2->next = node1;
    node1->next = next;
    p->next = node2;
    p = node1;
  }
  return node.next;
}

