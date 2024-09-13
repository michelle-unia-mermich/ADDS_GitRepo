main:
	g++ -std=c++11 -o test.o test.cpp Node.cpp LinkedList.cpp
	./test.o

cleanup:
	rm -rf *.o