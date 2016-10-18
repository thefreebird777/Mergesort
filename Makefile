Mergesort: Mergesort.o
	g++ Mergesort.o -o Mergesort

Mergesort.o: Mergesort.cpp
	g++ -c Mergesort.cpp

clean:
	rm *.o Mergesort
