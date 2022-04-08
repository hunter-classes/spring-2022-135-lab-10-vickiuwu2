main: main.o time.o 
	g++ -o main main.o time.o

tests: test.o time.o
	g++ -o tests tests.o time.o

main.o: main.cpp time.h 
	
time.o: time.cpp time.h 
	
test.o: test.cpp doctest.h time.h

clean:
	rm main.o time.o test.o