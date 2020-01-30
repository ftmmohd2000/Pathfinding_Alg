output: main.o NodeObject.o Graph.o Queue.o Stack.o Finders.o
	g++ main.o NodeObject.o Graph.o Queue.o Stack.o Finders.o -o output

main.o: main.cpp NodeObject.o Graph.o Finders.o
	g++ -c main.cpp

NodeObject.o: NodeObject.cpp NodeObject.h
	g++ -c NodeObject.cpp NodeObject.h

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp Graph.h

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp Queue.h

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp Stack.h

Finders.o: Finders.cpp Finders.h Stack.o Queue.o
	g++ -c Finders.cpp Finders.h

clean:
	rm *.o *.gch output 
