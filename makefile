lab10: main.o
	g++ -std=c++11 -g -Wall main.o -o lab10
main.o: main.cpp HeapLeftistMin.h HeapLeftistMin.hpp HeapSkewMin.h HeapSkewMin.hpp NodeHeapLeftist.h NodeHeapLeftist.hpp NodeHeapSkew.h NodeHeapSkew.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
clean:
	rm *.o lab10
