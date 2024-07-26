main:
	g++ -std=c++11 -o main.o main.cpp Player.cpp Human.cpp Computer.cpp Referee.cpp
	./main.o

cleanup:
	rm -rf *.o