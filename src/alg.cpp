// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> newTree;
  std::string slova = "";
  std::ifstream file(filename);
  char raznic = 'a' - 'A';
  if (!file) {
    throw std::cout << "File error!" << std::endl;
  } else {
    while (!file.eof()) {
      char sim = file.get();
      if ((sim >= 'a' && sim <= 'z') || (sim >= 'A' && sim <= 'Z')) {
        if (sim >= 'A' && sim <= 'Z') {
          sim = sim + raznic;
        }
        slova = slova + sim;
      } else if (slova != "") {
        newTree.add(slova);
        slova = "";
      }
    }
    return newTree;
    file.close();
  }
}
