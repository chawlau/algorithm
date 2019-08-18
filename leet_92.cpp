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
    printf(" %d ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

Node* reverse(Node* head) {
  Node* pre = NULL;
  Node* next = NULL;
  while (head) {
    Node* next = head->next;
    head->next = pre;
    pre = head;
    head= next;
  }
  return head;
}

Node* reverseBetween(Node* head, int m, int n) {
  if (m == n) return head;

  n -= m;

  Node dumy;
  dumy.next = head;
  Node* pre = &dumy;

  while (--m) pre = pre->next;
  Node* start = pre->next;

  while (n--) {
    Node* p = start->next;
    start->next = p->next;
    p->next = pre->next;
    pre->next = p;
  }
  return dumy.next;
}

//--m执行m-1
//m--执行m;
int main() {
  Node* head = NULL;
  insert_node(&head, 6);
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  print_node(head);
  Node* ret = reverseBetween(head, 3, 6);
  print_node(ret);
}
