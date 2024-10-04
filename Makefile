main:
	g++ -std=c++11 -o main.o main.cpp 
	./main.o

cleanup:
	rm -rf *.o