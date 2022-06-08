// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream file(filename);
  BST<std::string> newTree;
  std::string slova = "";
  char raznic = 'a' - 'A';
  if (!file) {
    std::cout << "File is not found" << std::endl;
    return newTree;
  }
  while (!file.eof()) {
    slova = "";
    char sim = file.get();
    if ((sim >= 'a' && sim <= 'z') || (sim >= 'A' && sim <= 'Z')) {
      if (sim >= 'A' && sim <= 'Z') {
        sim = sim + raznic;
      }
      slova = slova + sim;
    } else {
      break;
    }
    newTree.add(slova);
  }
  file.close();
  return newTree;
}
