#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int data;
  struct _Node* next;
}Node;

void insert_node(Node** head, int data) {
  Node* node = calloc(1, sizeof(Node));
  node->data = data;
  node->next = *head;
  *head = node;
}

void print_node(Node* head) {
  Node* temp = head;
  while (temp) {
    printf("node data %d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  insert_node(&head, 5);
  insert_node(&head, 4);
  insert_node(&head, 3);
  insert_node(&head, 2);
  insert_node(&head, 1);
  print_node(head);
}
