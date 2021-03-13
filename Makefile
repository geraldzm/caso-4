all:
	g++ -o main.out main.cpp
ex:
	g++ -o main.out main.cpp ; ./main.out
clean:
	rm *.o *.out *.exe
