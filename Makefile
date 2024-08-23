main:
	g++ -o main.o main.cpp Finder.cpp
	./main.o
cleanup:
	rm -rf *.o