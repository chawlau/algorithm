#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int val;
  struct _Node* next;
}Node;

void insert_node(Node** head, int val) {
  Node* node = calloc(1, sizeof(Node));
  node->val = val;
  node->next = *head;
  *head = node;
}

void print_node(Node* head) {
  Node* temp = head;
  while (temp) {
    printf("node val %d ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

Node* reverse_list(Node* head) {
  Node* pre = NULL;
  Node* next = NULL;

  while (head != NULL) {
    next = head->next;
    head ->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

int is_palindrome(Node* head) {
  if (head == NULL && head->next == NULL) {return 1;}
  Node* slow = head;
  Node* fast = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  slow->next = reverse_list(slow->next);
  slow = slow->next;

  while (slow != NULL) {
    if (head->val != slow->val) return 0;
    head = head->next;
    slow = slow->next;
  }

  return 1;
}

int main() {
  Node* head = NULL;
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  print_node(head);
  Node* new = reverse_list(head);
  //int ret = is_palindrome(head);
  //printf(" is_palind %d\n", ret);
  print_node(new);
}
