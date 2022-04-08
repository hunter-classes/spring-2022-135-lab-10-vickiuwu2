main: main.o time.o 
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o

main.o: main.cpp time.h 
	
time.o: time.cpp time.h 
	
test.o: tests.cpp doctest.h time.h

clean:
	rm -f main tests main.o time.o tests.o
