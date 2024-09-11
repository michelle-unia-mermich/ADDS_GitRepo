main_michelle:
	g++ -std=c++11 -o main_michelle.o main_michelle.cpp LinkedList.cpp Node.cpp
	./main_michelle.o
main_michelle2:
	g++ -std=c++11 -o main_michelle2.o main_michelle2.cpp BigNumCalc.cpp
	./main_michelle2.o
main:
	g++ -std=c++11 -o main.out -O2 -Wall *.cpp
	./main.out
cleanup:
	rm -rf *.o
	rm -rf *.out