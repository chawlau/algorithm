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

ListNode* partition(ListNode* head, int val) {
  ListNode node1(0), node2(0);
  ListNode* p1 = &node1;
  ListNode* p2 = &node2;

  while (head) {
    if (head->val < val) {
      p1->next = head;
      p1 = p1->next;
    } else {
      p2->next = head;
      p2 = p2->next;
    }
    head = head->next;
  }
  p2->next = nullptr;
  p1->next = node2.next;
  return node1.next;
}

int main() {
  ListNode* head = NULL;
  insert_node(&head, 2);
  insert_node(&head, 5);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 1);
  print_node(head);
  ListNode* ret = partition(head, 3);
  print_node(ret);
}
