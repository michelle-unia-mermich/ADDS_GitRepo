main:
	g++ -std=c++11 -o main.o main.cpp Truckloads.cpp Reverser.cpp

cleanup:
	rm -rf *.o