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

void recordList(ListNode* head);

int main() {
  ListNode* head1 = nullptr;
  insert_node(&head1, 6);
  insert_node(&head1, 5);
  insert_node(&head1, 4);
  insert_node(&head1, 3);
  insert_node(&head1, 2);
  insert_node(&head1, 1);
  print_node(head1);

  recordList(head1);
  print_node(head1);
}

ListNode* reverse(ListNode* head) {
  ListNode* pre = nullptr, *next = nullptr;

  while (head) {
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }

  return pre;
}

void recordList(ListNode* head) {
  if (!head || !head->next) return;

  ListNode* fast = head, *slow = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  slow->next = reverse(slow->next);

  ListNode* p1 = head;
  ListNode* p2 = slow->next;
  while (p1 != slow) {
    slow->next = p2->next;
    p2->next = p1->next;
    p1->next = p2;
    p1 = p2->next;
    p2 = slow->next;
  }
}
