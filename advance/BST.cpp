#include "heap.hpp"
#include "merge.h"
#include "quick_sort.h"
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST {
 private:
  struct Node {
    Key key;
    Value value;
    Node* left;
    Node* right;
    Node(Key key, Value value) {
      this->key = key;
      this->value = value;
      this->left = this->right = nullptr;
    }

    Node(Node *node){
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
    }
  };

  Node* root;
  int count;
 public:
  BST() {root = NULL; count = 0;}
  ~BST() {}

  int size() {return count;}
  bool isEmpty() {return count == 0;}
  void insert(Key key, Value value) {
    root = insert(root, key, value);
  }

  Value* search(Key key) {
    return search(root, key);
  }

  Node* insert(Node* root, Key key, Value value) {
    if (root == nullptr) {
      count ++;
      return new Node(key, value);
    }

    if (key == root->key)
      root->value = value;
    else if (root->key > key)
      root->left =  insert(root->left, key, value);
    else if (root->key < key)
      root->right = insert(root->right, key, value);
    return root;
  }

  bool contain(Node* root, Key key) {
    if (root == nullptr)
      return false;
    if (key == root->key)
      return true;
    else if (key > root->key)
      return contain(root->right, key);
    else if (key < root->key)
      return contain(root->left, key);
  }

  Node* search(Node* root, Key key) {
    if (root == nullptr)
      return nullptr;
    if (key == root->key)
      return &(root->value);
    else if (key > root->key)
      return contain(root->right, key);
    else if (key < root->key)
      return contain(root->left, key);
  }

  Node* remove(Node* node, Key key) {
    if (node == nullptr) return nullptr;

    if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    } else if (key > node->key) {
      node->right = remove(node->right, key);
      return node;
    } else {
      if (node->left == nullptr) {
        Node* right = node->right;
        delete node;
        count--;
        return right;
      }

      if (node->right == nullptr) {
        Node* left = node->left;
        delete node;
        count --;
        return left;
      }

      Node* suc = new Node(minimum(node->right));
      count++;
      suc->right = removeMin(node->right);
      suc->left = node->left;
      delete node;
      count--;
      return suc;
    }

  }

  void postOrder(Node* node){
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout<<node->key<<endl;
    }
  }

  void preOrder(Node* node){
    if( node != NULL ){
      cout<<node->key<<endl;
      preOrder(node->left);
      preOrder(node->right);
    }
  }

  void destroy(Node* node) {
    if (node != nullptr) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }

  void levelOrder() {
    queue<Node*> q;
    q.push(root);
    int level = 0;
    int end = 1;
    while (!q.empty()) {
      Node* node = q.front();
      cout << node->key << " ";
      if (node->left) {
        q.push(node->left);
        level++;
      }

      if (node->right) {
        q.push(node->right);
        level++;
      }
      q.pop();
      if (--end == 0) {
        cout << endl;
        end = level;
        level = 0;
      }
    }
  }

  Key minimum() {
    assert(count != 0);
    Node* minNode = minimum(root);
    return minNode->key;
  }

  Key maximum() {
    assert(count != 0);
    Node* maxNode = maximum(root);
    return maxNode->key;
  }

  void removeMin() {
    if (root)
      root = removeMin(root);
  }

  void removeMax() {
    if (root)
      root = removeMax(root);
  }

  Node* minimum(Node* node) {
    if (node->left == nullptr)
      return node;

    return minimum(node->left);
  }

  Node* maximum(Node* node) {
    if (node->right == nullptr)
      return node;

    return maximum(node->right);
  }

  Node* removeMin(Node* node) {
    if (node->left == nullptr) {
      Node* right = node->right;
      delete node;
      count--;
      return right;
    }

    node->left = removeMin(node->left);
    return node;
  }

  Node* removeMax(Node* node) {
    if (node->right == nullptr) {
      Node* left = node->left;
      delete node;
      return left;
    }
    node->right = removeMax(node->right);
    return node;
  }

  void RemoveMax() {
    root = removeMax(root);
  }

  void RemoveMin() {
    root = removeMin(root);
  }

  void Remove(Key key) {
    root = remove(root, key);
  }
};

//递归
//
int main() {
  BST<int, string> bst;
  bst.insert(8, "8");
  bst.insert(6, "6");
  bst.insert(10, "10");
  bst.insert(5, "5");
  bst.insert(7, "7");
  bst.insert(9, "9");
  bst.insert(11, "11");
  bst.levelOrder();
  //bst.RemoveMax();
  //bst.levelOrder();
  //bst.RemoveMin();
  //bst.levelOrder();
  bst.Remove(8);
  bst.levelOrder();
}

