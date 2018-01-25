all:
	g++ -pthread -std=c++0x main.cpp
run: main.cpp
	./a.out 10 11 3 7 8 9
