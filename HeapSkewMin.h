#ifndef HEAPSKEWMIN_H
#define HEAPSKEWMIN_H

#include <string>
#include <fstream>
#include <iostream>

#include "NodeHeapSkew.h"

//This Class is an implementation of an Integer HeapSkewMin

class HeapSkewMin
{
private:
  NodeHeapSkew* m_root;     //Root node of the heap
  int m_size;                       //Size tracker for convenience

public:
  //Constructor
  HeapSkewMin(std::string fName);

  //Destructor
  ~HeapSkewMin();

  //Insert a given value to the Heap
  void insert(int value);

  //Concatenate two Min Skew Heaps
  void concat(NodeHeapSkew* heap1, NodeHeapSkew* heap2);

  //Merge Two subtrees
  NodeHeapSkew* merge(NodeHeapSkew* n1, NodeHeapSkew* n2);

  //Delete minimum/maximum values from Heap
  void deleteMin();

  //Traversals
  void levelorder();
  void preorder(NodeHeapSkew* sub);
  void inorder(NodeHeapSkew* sub);

  //Return the root
  NodeHeapSkew* getRoot();

};

#include "HeapSkewMin.hpp"

#endif
