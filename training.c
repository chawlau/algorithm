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
  Node* next = NULL;
  Node* pre = NULL;
  while (head) {
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

Node* make_circle_list() {
  int i = 0;
  Node* head = NULL;
  Node* tail = NULL;
  for (i = 0; i < 5; i++) {
    Node* node = calloc(1, sizeof(Node));
    node->val = 5 - i;
    node->next = NULL;

    if (tail == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  tail->next = head;
  return head;
}

Node* make_list2() {
  Node* head = NULL;
  insert_node(&head, 10);
  insert_node(&head, 8);
  insert_node(&head, 6);
  insert_node(&head, 4);
  insert_node(&head, 2);
  return head;
}

Node* make_list1() {
  Node* head = NULL;
  insert_node(&head, 9);
  insert_node(&head, 7);
  insert_node(&head, 5);
  insert_node(&head, 3);
  insert_node(&head, 1);
  return head;
}

Node* make_list() {
  Node* head = NULL;
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  return head;
}


int circle_check(Node* head) {
  if (head == NULL) return 1;
  Node* slow = head;
  Node* fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow->val == fast->val) {
      return 1;
    }
  }
  return 0;
}

Node* merge_list(Node* l1, Node* l2) {
  Node dummy = {
    .val = 0,
    .next = NULL,
  };
  Node* tail = &dummy;

  while (l1 && l2) {
    if (l1->val < l2->val) {
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }
  tail->next = l1 ? l1 : l2;
  print_node(dummy.next);
  return dummy.next;
}

void delete_last_kth(int k, Node** head) {
  if (*head == NULL || k == 0) return ;
  int i = 0;
  Node* fast = *head;
  while (fast && i < k - 1) {
    fast = fast->next;
    i++;
  }

  if (fast == NULL) return ;

  Node* pre = NULL;
  Node* slow = *head;
  while (fast->next) {
    slow = slow->next;
    pre = slow;
    fast = fast->next;
  }

  if (!pre) {
    *head = (*head)->next;
  } else {
    pre->next = slow->next;
  }
  free(slow);

  print_node(*head);
  return ;
}

int main() {
  Node* list1 = make_list1();
  print_node(list1);
  delete_last_kth(3, &list1);
}
