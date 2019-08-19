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

ListNode* isPalindrome(ListNode* head);

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

bool isPalindrome(ListNode* head) {
  ListNode* fast = head, *slow = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  slow->next = reverse(slow->next);
  slow = slow->next;

  while (slow && head) {
    if (slow->val != head->val)
      return false;
    slow = slow->next;
    head = head->next;
  }
  return true;
}
