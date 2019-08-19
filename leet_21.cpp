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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode node(0), *p = &node;

  while (l1 && l2) {
    if (l1->val < l2->val) {
      p->next = l1;
      l1 = l1->next;
    } else {
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }

  p->next = l1 ? l1 : l2;
  return node.next;
}

int main() {
  ListNode* head1 = nullptr;
  insert_node(&head1, 4);
  insert_node(&head1, 2);
  insert_node(&head1, 1);

  ListNode* head2 = nullptr;
  insert_node(&head2, 5);
  insert_node(&head2, 4);
  insert_node(&head2, 3);
  insert_node(&head2, 1);
  print_node(head1);
  print_node(head2);
  ListNode* ret = mergeTwoLists(head1, head2);
  print_node(ret);
}
