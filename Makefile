bubble:
	g++ -o testBubbleSort.o -std=c++11 -O2 -Wall testBubbleSort.cpp BubbleSort.cpp 
	./testBubbleSort.o
quicksort:
	g++ -o testQuickSort.o -std=c++11 -O2 -Wall testQuickSort.cpp QuickSort.cpp
	./testQuickSort.o
binarysearch:
	g++ -o binarysearch.o -std=c++11 -O2 -Wall testRecursiveBinarySearch.cpp QuickSort.cpp RecursiveBinarySearch.cpp
	./binarysearch.o
main:
	g++ -o main.o -std=c++11 -O2 -Wall main.cpp QuickSort.cpp RecursiveBinarySearch.cpp BubbleSort.cpp 
	./main.o
cleanup:
	rm -rf *.o

#Remember: if you have the mistake linker command code -v1, very likekly you forgot to include all *.cpp in makefile