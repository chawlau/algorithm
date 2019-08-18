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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode node(0), *p = &node;
  int extra = 0;
  while (l1 || l2 || extra) {
    if (l1) extra += l1->val, l1 = l1->next;
    if (l2) extra += l2->val, l2 = l2->next;
    p->next = new ListNode(extra % 10);
    extra /= 10;
    p = p->next;
  }
  return node.next;
}

int main() {
  ListNode* head = nullptr;
  insert_node(&head, 6);
  insert_node(&head, 5);
  insert_node(&head, 4);

  ListNode* head2 = nullptr;
  insert_node(&head2, 5);
  insert_node(&head2, 6);
  insert_node(&head2, 7);
  print_node(head);
  print_node(head2);
  ListNode* ret = addTwoNumbers(head, head2);
  print_node(ret);
}
