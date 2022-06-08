// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream text(filename);
  BST<std::string> newTree;
  std::string slova = "";
  char raznic = 'a' - 'A';
  if (!file) {
    std::cout << "File is not found" << std::endl;
    return newTree;
  }
  while (!file.eof()) {
    char sim = text.get();
    if (sim >= 'A' && sim <= 'Z') {
      sim = sim + raznic;
    } else if (('z' >= sim) && ('a' <= sim)) {
      slova = slova + sim;
    } else {
      newTree.add(slova);
      slova = "";
    }
  }
  text.close();
  return newTree;
}
