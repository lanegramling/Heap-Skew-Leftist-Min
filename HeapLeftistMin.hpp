
#include <math.h>
#include "HeapLeftistMin.h"

///////////////////////////////////////////////////////////////////////////
//Briefly defined queue for levelorder traversals
struct qNodeL
{
  int height; //For convenience
  NodeHeapLeftist* me;
  qNodeL* next = nullptr;
};
typedef struct _queue_leftist
{
  qNodeL* front;
} queue_leftist_t;
queue_leftist_t* makeQueue(NodeHeapLeftist* root)
{
  queue_leftist_t* newQ = new queue_leftist_t;
  newQ->front = new qNodeL;
  newQ->front->me = root;
  newQ->front->height = 0;
  return newQ;
}
void qPush(queue_leftist_t* q, NodeHeapLeftist* node, int height)
{
  qNodeL* current = q->front;          //Start at front. Traverse to end. Append.
  if (current) {
    if (!current->me) { current->me = node; return; }
    else while (current->next) current = current->next;
    qNodeL* newNode = new qNodeL;
    newNode->height = height;
    newNode->me = node;
    current->next = newNode;
  } else {
    q->front = new qNodeL;
    q->front->height = height;
    q->front->me = node;
    q->front->next = nullptr;
  }
}
NodeHeapLeftist* qPop(queue_leftist_t* q)
{
  if (!q->front) return nullptr;       //Pop from front.
  qNodeL* temp = q->front;
  q->front = q->front->next;
  NodeHeapLeftist* popped = temp->me;
  delete temp;
  return popped;
}
void qDestroy(queue_leftist_t* q)
{
  while(qPop(q));
  delete q;
}
///////////////////////////////////////////////////////////////////////////

//Constructor
HeapLeftistMin::HeapLeftistMin(std::string fName)
{
  std::ifstream file(fName);
  if (file.is_open()) {
    int num = 0;
    while (file >> num) {
       std::cout << "\nInserting " << num;
       insert(num);
     }
    file.close();
  } else {
    std::cout << "\nUnable to open " << fName << ". Please review the correctness of this file."
              << "\nDefaulting to empty tree.";
    m_root = nullptr;
  }
}

//Destructor
HeapLeftistMin::~HeapLeftistMin()
{
  while(m_root) deleteMin();
}

//Insert a given value to the Heap
void HeapLeftistMin::insert(int value)
{
  NodeHeapLeftist* newNode = new NodeHeapLeftist(value);
  if (m_root == nullptr) m_root = newNode;
  else concat(m_root, newNode);
}

//Concatenate two Min Leftist Heaps.
void HeapLeftistMin::concat(NodeHeapLeftist* heap1, NodeHeapLeftist* heap2)
{
  heap1 = merge(heap1, heap2);
}

//Merge Two subtrees
NodeHeapLeftist* HeapLeftistMin::merge(NodeHeapLeftist* n1, NodeHeapLeftist* n2)
{
  if (!n2) return n1;
  else if (!n1) return n2;
  else {

    //Order subtrees properly, then recurse
    if (n1->getValue() > n2->getValue()) {
      if (n1 == m_root) m_root = n2; //If we're about to swap the root, update it
      NodeHeapLeftist* temp = n1;
      n1 = n2;
      n2 = temp;
    }
    n1->setRightChild(merge(n1->getRightChild(), n2));

    //Calculate rank of children...
    int lc_rank = (n1->getLeftChild()) ? n1->getLeftChild()->getRank() : 0;
    int rc_rank = (n1->getRightChild()) ? n1->getRightChild()->getRank() : 0;

    //...then swap them if necessary.
    if (lc_rank < rc_rank) {
      NodeHeapLeftist* temp = n1->getLeftChild();
      n1->setLeftChild(n1->getRightChild());
      n1->setRightChild(temp);
    }

    return n1;
  }
}

//Delete minimum/maximum values from Heap
void HeapLeftistMin::deleteMin()
{
  NodeHeapLeftist* temp = m_root;
  m_root = merge(m_root->getLeftChild(), m_root->getRightChild());
  delete temp;
}

//Recursive levelorder function. takes the 'current' height of the children
// and newlines when it updates.
void printLevel(queue_leftist_t* q, int level)
{
  if (!q->front) return;
  if (level != q->front->height) { std::cout << "\n"; level++; } //Newline case

  NodeHeapLeftist* current = qPop(q); //Pop from the front, queue its children.
  if (current->getLeftChild()) qPush(q, current->getLeftChild(), level+1);
  if (current->getRightChild()) qPush(q, current->getRightChild(), level+1);
  std::cout << current->getValue() << "  "; //Print the value.
  printLevel(q, level);
}

//Level-Order Traversal
void HeapLeftistMin::levelorder()
{
  std::cout << "\n";
  queue_leftist_t* q = makeQueue(m_root);
  printLevel(q, 0);
  qDestroy(q);
}
//Pre-Order Traversal
void HeapLeftistMin::preorder(NodeHeapLeftist* sub)
{
  if (!sub) return;
  std::cout << sub->getValue() << " ";
  preorder(sub->getLeftChild());
  preorder(sub->getRightChild());
}
//In-Order Traversal
void HeapLeftistMin::inorder(NodeHeapLeftist* sub)
{
  if (!sub) return;
  inorder(sub->getLeftChild());
  std::cout << sub->getValue() << " ";
  inorder(sub->getRightChild());
}

NodeHeapLeftist* HeapLeftistMin::getRoot()
{ return m_root; }

// void HeapLeftistMin::deleteMax()
// {
//   NodeHeapLeftist* temp = findMax(m_root);
//   m_root = merge(m_root->getLeftChild(), m_root->getRightChild());
//   delete temp;
//   m_size--;
// }

// //Find minimum/maximum values in Heap
// NodeHeapLeftist* HeapLeftistMin::findMin()
// {
//   return m_root;
// }
// NodeHeapLeftist* HeapLeftistMin::findMax(NodeHeapLeftist* subtree)
// {
//   NodeHeapLeftist* leftMax;
//   NodeHeapLeftist* rightMax;
//   if (!subtree) return nullptr;
//   else if (subtree->getLeftChild()) leftMax = findMax(subtree->getLeftChild());
//   else if (subtree->getRightChild()) rightMax = findMax(subtree->getRightChild());
//
//   if (!leftMax) return rightMax;
//   else if (!rightMax) return leftMax;
//   else return (leftMax->getValue() > rightMax->getValue()) ? leftMax : rightMax;
// }
// //Get minimum/maximum values in Heap
// int HeapLeftistMin::getMin()
// { return findMin()->getValue(); }
// int HeapLeftistMin::getMax()
// { return findMax(m_root)->getValue(); }
// int HeapLeftistMin::getSize()
// { return m_size; }
