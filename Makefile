output: main.o NodeObject.o Graph.o
	g++ main.o NodeObject.o Graph.o -o output

main.o: main.cpp
	g++ -c main.cpp

NodeObject.o: NodeObject.cpp
	g++ -c NodeObject.cpp NodeObject.h

Graph.o: Graph.cpp
	g++ -c Graph.cpp Graph.h

clean:
	rm *.o *.gch output
