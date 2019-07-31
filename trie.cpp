#include <iostream>

struct TrieNode {
  char _data;
  TrieNode children[26];
  bool is_end;
  TrieNode(char data) : _data(data) {}
}

struct Trie {
  TrieNode* root;
  void Insert(char[] text, int n) {
    TrieNode* p = root;

    for (int i = 0; i < n; ++i) {
      int index = text[i] - 'a';
      if (p->children[index] == NULL) {
        TrieNode* new_node = new TrieNode(text[i]);
        p->children[index] = new_node;
      }
      p = p->children[index];
    }
    p->is_end = true;
  }

  Trie(char data) : root(new TrieNode(char)) {}

  bool find(char[] pattern, int n) {
    TrieNode* p = root;
    for (int i = 0; i < n, i++) {
      int index = pattern[i] - 'a';

      if (p->children[index] == NULL)
        return false;

      p = p->children[index];
    }

    if (p->is_end = false)
      return false;
    else
      return true;
  }
}

int main() {
  return 0;
}
