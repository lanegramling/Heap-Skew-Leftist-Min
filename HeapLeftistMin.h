#ifndef HEAPLEFTISTMIN_H
#define HEAPLEFTISTMIN_H

#include <string>
#include <fstream>
#include <iostream>

#include "NodeHeapLeftist.h"

//This Class is an implementation of an Integer HeapLeftistMin

class HeapLeftistMin
{
private:
  NodeHeapLeftist* m_root;     //Root node of the heap
  int m_size;                       //Size tracker for convenience

public:
  //Constructor
  HeapLeftistMin(std::string fName);

  //Destructor
  ~HeapLeftistMin();

  //Insert a given value to the Heap
  void insert(int value);

  //Concatenate two Min Leftist Heaps
  void concat(NodeHeapLeftist* heap1, NodeHeapLeftist* heap2);

  //Merge Two subtrees
  NodeHeapLeftist* merge(NodeHeapLeftist* n1, NodeHeapLeftist* n2);

  //Delete minimum/maximum values from Heap
  void deleteMin();

  //Traversals
  void levelorder();
  void preorder(NodeHeapLeftist* sub);
  void inorder(NodeHeapLeftist* sub);

  //Return the root
  NodeHeapLeftist* getRoot();

  // void deleteMax();

  //Find minimum/maximum values in Heap
  // NodeHeapLeftist* findMin();
  // NodeHeapLeftist* findMax(NodeHeapLeftist* subtree);

  //Get minimum/maximum values in Heap
  // int getMin();
  // int getMax();
  // int getSize();

};

#include "HeapLeftistMin.hpp"

#endif
