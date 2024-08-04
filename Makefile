main:
	g++ -std=c++11 -o main.o main.cpp Player.cpp Human.cpp Computer.cpp Referee.cpp Move.cpp MoveFactory.cpp Rock.cpp Paper.cpp Scissors.cpp Monkey.cpp Ninja.cpp Robot.cpp Pirate.cpp Zombie.cpp
	./main.o

cleanup:
	rm -rf *.o