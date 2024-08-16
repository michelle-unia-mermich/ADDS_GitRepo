question1:
	g++ -o question1.o main.cpp question1.cpp
	./question1.o
question2:
	g++ -o question2.o question2.cpp main.cpp
	./question2.o
cleanup:
	rm -rf *.o