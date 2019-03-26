#include "NodeHeapSkew.h"

//NOTE: Makes use of the queue defined in the HeapLeftistMin class.

//Constructor
NodeHeapSkew::NodeHeapSkew(int value, NodeHeapSkew* leftChild, NodeHeapSkew* rightChild)
{
    m_value = value;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
}

//Set the value of this NodeHeapSkew.
void NodeHeapSkew::setValue(int value)
{m_value = value;}

//Get the value of this NodeHeapSkew.
int NodeHeapSkew::getValue()
{return m_value;}

//Set the left child
void NodeHeapSkew::setLeftChild(NodeHeapSkew* leftChild)
{m_leftChild = leftChild;}

//Set the right child
void NodeHeapSkew::setRightChild(NodeHeapSkew* rightChild)
{m_rightChild = rightChild;}

//Get the left child
NodeHeapSkew* NodeHeapSkew::getLeftChild() const
{return m_leftChild;}

//Get the left child
NodeHeapSkew* NodeHeapSkew::getRightChild() const
{return m_rightChild;}

//Return whether the Node is a leaf.
bool NodeHeapSkew::isLeaf()
{ return !getLeftChild() && !getRightChild(); }
