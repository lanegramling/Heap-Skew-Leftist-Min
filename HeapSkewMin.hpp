
#include <math.h>
#include "HeapSkewMin.h"

///////////////////////////////////////////////////////////////////////////
//Briefly defined queue for levelorder traversals
struct qNodeS
{
  int height; //For convenience
  NodeHeapSkew* me;
  qNodeS* next = nullptr;
};
typedef struct _queue_skew
{
  qNodeS* front;
} queue_skew_t;
queue_skew_t* makeQueue(NodeHeapSkew* root)
{
  queue_skew_t* newQ = new queue_skew_t;
  newQ->front = new qNodeS;
  newQ->front->me = root;
  newQ->front->height = 0;
  return newQ;
}
void qPush(queue_skew_t* q, NodeHeapSkew* node, int height)
{
  qNodeS* current = q->front;          //Start at front. Traverse to end. Append.
  if (current) {
    if (!current->me) { current->me = node; return; }
    else while (current->next) current = current->next;
    qNodeS* newNode = new qNodeS;
    newNode->height = height;
    newNode->me = node;
    current->next = newNode;
  } else {
    q->front = new qNodeS;
    q->front->height = height;
    q->front->me = node;
    q->front->next = nullptr;
  }
}
NodeHeapSkew* qPop(queue_skew_t* q)
{
  if (!q->front) return nullptr;       //Pop from front.
  qNodeS* temp = q->front;
  q->front = q->front->next;
  NodeHeapSkew* popped = temp->me;
  delete temp;
  return popped;
}
void qDestroy(queue_skew_t* q)
{
  while(qPop(q));
  delete q;
}
///////////////////////////////////////////////////////////////////////////

//Constructor
HeapSkewMin::HeapSkewMin(std::string fName)
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
HeapSkewMin::~HeapSkewMin()
{
  while(m_root) deleteMin();
}

//Insert a given value to the Heap
void HeapSkewMin::insert(int value)
{
  NodeHeapSkew* newNode = new NodeHeapSkew(value);
  if (m_root == nullptr) m_root = newNode;
  else concat(m_root, newNode);
}

//Concatenate two Min Skew Heaps.
void HeapSkewMin::concat(NodeHeapSkew* heap1, NodeHeapSkew* heap2)
{
  heap1 = merge(heap1, heap2);
}

//Merge Two subtrees
NodeHeapSkew* HeapSkewMin::merge(NodeHeapSkew* n1, NodeHeapSkew* n2)
{
  if (!n2) return n1;
  else if (!n1) return n2;
  else {

    //Order subtrees properly, then recurse
    if (n1->getValue() > n2->getValue()) {
      if (n1 == m_root) m_root = n2; //If we're about to swap the root, update it
      NodeHeapSkew* temp = n1;
      n1 = n2;
      n2 = temp;
    }
    n1->setRightChild(merge(n1->getRightChild(), n2));
    NodeHeapSkew* temp = n1->getLeftChild();
    n1->setLeftChild(n1->getRightChild());
    n1->setRightChild(temp);
    return n1;
  }
}

//Delete minimum/maximum values from Heap
void HeapSkewMin::deleteMin()
{
  NodeHeapSkew* temp = m_root;
  m_root = merge(m_root->getLeftChild(), m_root->getRightChild());
  delete temp;
}

//Recursive levelorder function. takes the 'current' height of the children
// and newlines when it updates.
void printLevel(queue_skew_t* q, int level)
{
  if (!q->front) return;
  if (level != q->front->height) { std::cout << "\n"; level++; } //Newline case

  NodeHeapSkew* current = qPop(q); //Pop from the front, queue its children.
  if (current->getLeftChild()) qPush(q, current->getLeftChild(), level+1);
  if (current->getRightChild()) qPush(q, current->getRightChild(), level+1);
  std::cout << current->getValue() << "  "; //Print the value.
  printLevel(q, level);
}

//Level-Order Traversal
void HeapSkewMin::levelorder()
{
  std::cout << "\n";
  queue_skew_t* q = makeQueue(m_root);
  printLevel(q, 0);
  qDestroy(q);
}
//Pre-Order Traversal
void HeapSkewMin::preorder(NodeHeapSkew* sub)
{
  if (!sub) return;
  std::cout << sub->getValue() << " ";
  preorder(sub->getLeftChild());
  preorder(sub->getRightChild());
}
//In-Order Traversal
void HeapSkewMin::inorder(NodeHeapSkew* sub)
{
  if (!sub) return;
  inorder(sub->getLeftChild());
  std::cout << sub->getValue() << " ";
  inorder(sub->getRightChild());
}

NodeHeapSkew* HeapSkewMin::getRoot()
{ return m_root; }
