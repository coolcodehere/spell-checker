output: main.o Dictionary.o
	g++ main.o Dictionary.o -o output

main.o: main.cpp
	g++ -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp