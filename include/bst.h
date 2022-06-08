// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST<T> {
 private:
  struct Node {
    T value;
    int count;
    Node * left, * right;
  };
  Node * root;
  Node * addNode(Node * root, T val);
  int searchNode(Node * root, T val);
  int heightTree(Node * root);
 public:
  void add(T value);
  int search(T value);
  int depth();
};

template<typename T>
BST<T>::BST() {root == nullptr;}

template BST<T>*BST<T>::addNode(Node * root, T val) {
  if (root = nullptr) {
    root = newNode;
    root -> value = val;
    root -> count = 1;
    root -> left = root -> right = nullptr;
  } else if (val < root -> left) {
    root -> left = addNode(root -> left, val);
  } else if (val > root -> value) {
    root -> right = addNode(root -> right, val);
  } else {
    root -> count++;
    return n;
  }
}

template<typename T>
int BST<T>::searchNode(Node * root, T val) {
  if (root == nullptr)
    return 0;
  else if (root -> value = val)
    return root -> count;
  else if (root -> value > val)
    return searchNode(root -> left, val);
  else
    return searchNode(root->right, val);
}

template<typename T>
int BST<T>::heightTree(Node * root) {
  if (root == nullptr) {
    return 0;
  } else {
    int l = heightTree(root -> left);
    int r = heightTree(root -> right);
    if (l > r)
      return l + 1;
    else
      return r + 1;
  }
}

template<typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}

template<typename T>
int BST<T>::search(T value) {
  return searchNode(root, value);
}

template<typename T>
int BST<T>::depth() {
  return heightTree(root);
}
#endif  // INCLUDE_BST_H_
