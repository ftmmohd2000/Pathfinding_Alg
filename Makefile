output: main.o NodeObject.o Graph.o Finders.o Queue.o Stack.o
	g++ main.o NodeObject.o Graph.o Queue.o Stack.o -o output

main.o: main.cpp
	g++ -c main.cpp

NodeObject.o: NodeObject.cpp NodeObject.h
	g++ -c NodeObject.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Finders.o: Finders.cpp Finders.h
	g++ -c Finders.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

clean:
	rm *.o output
