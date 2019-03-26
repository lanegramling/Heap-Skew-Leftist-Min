#ifndef NODEHEAPSKEW_H
#define NODEHEAPSKEW_H

class NodeHeapSkew
{
public:
  //Constructor
  NodeHeapSkew(int value, NodeHeapSkew* leftChild=nullptr, NodeHeapSkew* rightChild=nullptr);

  //Set the value of this NodeHeapSkew.
  void setValue(int value);

  //Get the value of this NodeHeapSkew.
  int getValue();

  //Set the pointer to the Left child.
  void setLeftChild(NodeHeapSkew* leftPtr);

  //Set the pointer to the Right child.
  void setRightChild(NodeHeapSkew* rightPtr);

  //Get the pointer to the Left child.
  NodeHeapSkew* getLeftChild() const;

  //Get the pointer to the Right child.
  NodeHeapSkew* getRightChild() const;

  //Get the rank of the Node
  int getRank();

  //Determine whether this NodeHeapSkew is a leaf, for convenience.
  bool isLeaf();


private:

  //Skew Heap - Node Structure
  int m_value;      //Value stored in this NodeHeapSkew

  NodeHeapSkew* m_leftChild;       //Left Child Pointer
  NodeHeapSkew* m_rightChild;      //Right Child Pointer
};

#include "NodeHeapSkew.hpp"

#endif
