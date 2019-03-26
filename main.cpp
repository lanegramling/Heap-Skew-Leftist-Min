#include <iostream>   //I/O
#include <fstream>    //File Input handling
#include <string>     //String convenience

#include "HeapLeftistMin.h"	              //Heaps
#include "HeapSkewMin.h"	              //Heaps

//Load a HeapLeftistMin from a (.txt) file
HeapLeftistMin* loadHeapLeftistMin(std::string fName) {
  std::cout << "\n\nAttempting to create a Leftist min-heap from table from file " << fName << "...";
  HeapLeftistMin* heap = new HeapLeftistMin(fName);
  return heap;
}

// Load a HeapSkewMin from a (.txt) file
HeapSkewMin* loadHeapSkewMin(std::string fName) {
  std::cout << "\n\nAttempting to create a Skew min-heap from table from file " << fName << "...";
  HeapSkewMin* heap = new HeapSkewMin(fName);
  return heap;
}

//Main function
int main(int argc, char* argv[])
{
  //Initialization
  std::string fileName = (argv[1]) ? argv[1] : "data.txt"; //File name assignment
  if (argv[1]) std::cout << "\nReading '" << argv[1] << "'..."; else "\nDefaulting to 'data.txt'...";

  //Create the heaps from the given type and input file.
  HeapLeftistMin* heapL = loadHeapLeftistMin(fileName);
  HeapSkewMin* heapS = loadHeapSkewMin(fileName);

  //Main IO loop - controls interaction with created HeapLeftistMin.
	int choice = 0;
	do {
    std::cout << "\n\n................................................................"
									<< "\nPlease choose one of the following commands:"
									<< "\n1-	Insert"
                  << "\n2-	DeleteMin"
                  << "\n3-	Preorder"
                  << "\n4-	Inorder"
                  << "\n5- 	Levelorder"
                  << "\n6-	Exit"
									<< "\n> ";
    std::cin >> choice;
		int num = 0; //Contains I/O responses
    switch(choice) {
      case 1: //Handle Insert
        std::cout << "\nEnter a number to be inserted: \n> ";
				std::cin >> num;
        heapL->insert(num);
        heapS->insert(num);
        break;
      case 2: //Handle DeleteMin
        std::cout << "\nDeleting min from heaps...";
        heapL->deleteMin();
        heapS->deleteMin();
        break;
      case 3: //Handle Preorder
        std::cout << "\nLeftist Heap -> Pre-order: \n";
        heapL->preorder(heapL->getRoot());
        std::cout << "\n\nSkew Heap -> Pre-order: \n";
        heapS->preorder(heapS->getRoot());
        break;
      case 4: //Handle Inorder
        std::cout << "\nLeftist Heap -> In-order: \n";
        heapL->inorder(heapL->getRoot());
        std::cout << "\n\nSkew Heap -> In-order: \n";
        heapS->inorder(heapS->getRoot());
        break;
      case 5: //Handle Levelorder
        std::cout << "\nLeftist Heap -> Level-order: \n";
        heapL->levelorder();
        std::cout << "\n\nSkew Heap -> Level-order: \n";
        heapS->levelorder();
        // heapS->deleteMax();
        break;
      case 6: break; //Handle Exit
      default:
        std::cout << "\nThat option was not found. Please try again.";
        break;
    }

} while (choice != 6);
  std::cout << "\n\nExiting - dumping heap...\n";
  delete heapL;
  delete heapS;
}
