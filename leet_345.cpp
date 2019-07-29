#include <iostream>
#include <cstdio>
#include <cstdlib>

void swap(char& a, char& b) {
  char temp = a;
  a = b;
  b = temp;
}

void reverse_string(char a[], int n) {
  int i = 0, j = n - 1;
  while (i < j) {
    swap(a[i++], a[j--]);
  }
}

int main() {
  char a[] = "hello";
  reverse_string(a, 5);
  for (auto& it : a)
    printf("%c ", it);
  printf("\n");
}
