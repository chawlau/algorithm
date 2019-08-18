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


ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
  ListNode node(0), *p = &node;
  std::vector<int> num1, num2;
  while (l1) num1.push_back(l1->val), l1 = l1->next;
  while (l2) num2.push_back(l2->val), l2 = l2->next;

  int extra = 0, i = num1.size(), j = num2.size();
  ListNode* pre = nullptr;
  while (i > 0|| j > 0|| extra) {
    if (--i >= 0) extra += num1[i];
    if (--j >= 0) extra += num2[j];
    ListNode* node = new ListNode(extra % 10);
    node->next = pre;
    pre = node;
    p->next = pre;
    extra /= 10;
  }
  return node.next;
}

int main() {
  ListNode* head = nullptr;
  insert_node(&head, 6);
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 2);

  ListNode* head2 = nullptr;
  insert_node(&head2, 5);
  insert_node(&head2, 6);
  insert_node(&head2, 7);
  print_node(head);
  print_node(head2);
  ListNode* ret = addTwoNumbersII(head, head2);
  print_node(ret);
}
