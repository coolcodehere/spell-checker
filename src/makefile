output: main.o Dictionary.o ArrayList.o
	g++ main.o Dictionary.o ArrayList.o -o output

main.o: main.cpp
	g++ -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h Primes.h
	g++ -c Dictionary.cpp

ArrayList.o: ArrayList.cpp ArrayList.h
	g++ -c ArrayList.cpp

clean: 
	rm *.o