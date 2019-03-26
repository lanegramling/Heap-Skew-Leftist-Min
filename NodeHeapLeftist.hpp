#include "NodeHeapLeftist.h"

//Constructor
NodeHeapLeftist::NodeHeapLeftist(int value, NodeHeapLeftist* leftChild, NodeHeapLeftist* rightChild)
{
    m_value = value;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
}

//Set the value of this NodeHeapLeftist.
void NodeHeapLeftist::setValue(int value)
{m_value = value;}

//Get the value of this NodeHeapLeftist.
int NodeHeapLeftist::getValue()
{return m_value;}

//Set the left child
void NodeHeapLeftist::setLeftChild(NodeHeapLeftist* leftChild)
{m_leftChild = leftChild;}

//Set the right child
void NodeHeapLeftist::setRightChild(NodeHeapLeftist* rightChild)
{m_rightChild = rightChild;}

//Get the left child
NodeHeapLeftist* NodeHeapLeftist::getLeftChild() const
{return m_leftChild;}

//Get the left child
NodeHeapLeftist* NodeHeapLeftist::getRightChild() const
{return m_rightChild;}

//Return whether the Node is a leaf.
bool NodeHeapLeftist::isLeaf()
{ return !getLeftChild() && !getRightChild(); }

//Get the rank of the Node
int NodeHeapLeftist::getRank()
{
  if (isLeaf()) {
    return 1;
  } else {
    int lc_rank = (m_leftChild) ? m_leftChild->getRank() : 0;
    int rc_rank = (m_rightChild) ? m_rightChild->getRank() : 0;
    m_rank = 1 + ((lc_rank < rc_rank) ? lc_rank : rc_rank);
    return m_rank;
  }
}
