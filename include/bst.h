// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node * left, * right;
  };
  Node * root;
  int searchNode(Node * root, T val) {
    if (root == nullptr)
      return 0;
    else if (root -> value == val)
      return root -> count;
    else if (root -> value > val)
      return searchNode(root -> left, val);
    else
      return searchNode(root -> right, val);
  }
  Node * addNode(Node * root, T val) {
    if (root = nullptr) {
      root = new Node;
      root -> value = val;
      root -> count = 1;
      root -> left = root -> right = nullptr;
    } else if (val < root->value) {
      root->left = addNode(root->left, val);
    } else if (val > root->value) {
      root->right = addNode(root->right, val);
    } else {
      root->count++;
    }
      return root;
  }
  int heightTree(Node * root) {
    if (root == nullptr) {
     return 0;
    } else {
      int l = heightTree(root -> left);
      int r = heightTree(root -> right);
      if (l > r)
        return l++;
      else
        return r++;
    }
  }

 public:
  BST() :root(nullptr) {}
  int search(T value) {
    return searchNode(root, value);
  }
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return heightTree(root);
  }
};
#endif  // INCLUDE_BST_H_
