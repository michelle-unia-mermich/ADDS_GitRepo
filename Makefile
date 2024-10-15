main:
	g++ -std=c++11 -o main.o main.cpp 
	./main.o
main_clean: #this is the final one
	g++ -std=c++11 -o main_clean.o main_clean.cpp 
	./main_clean.o
test:
	g++ -std=c++11 -o test.o test.cpp 
	./test.o
cleanup:
	rm -rf *.o