#ifndef NODEHEAPLEFTIST_H
#define NODEHEAPLEFTIST_H


class NodeHeapLeftist {

public:

  //Constructor
  NodeHeapLeftist(int value, NodeHeapLeftist* leftChild=nullptr, NodeHeapLeftist* rightChild=nullptr);

  //Set the value of this NodeHeapLeftist.
  void setValue(int value);

  //Get the value of this NodeHeapLeftist.
  int getValue();

  //Set the pointer to the Left child.
  void setLeftChild(NodeHeapLeftist* leftPtr);

  //Set the pointer to the Right child.
  void setRightChild(NodeHeapLeftist* rightPtr);

  //Get the pointer to the Left child.
  NodeHeapLeftist* getLeftChild() const;

  //Get the pointer to the Right child.
  NodeHeapLeftist* getRightChild() const;

  //Get the rank of the Node
  int getRank();
  
  //Determine whether this NodeHeapLeftist is a leaf, for convenience.
  bool isLeaf();


private:

  //Leftist Heap - Node Structure
  int m_rank;     //Rank
  int m_value;      //Value stored in this NodeHeapLeftist

  NodeHeapLeftist* m_leftChild;       //Left Child Pointer
  NodeHeapLeftist* m_rightChild;      //Right Child Pointer




};

#include "NodeHeapLeftist.hpp"

#endif
