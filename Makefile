output: main.o NodeObject.o Graph.o Finder.o
	g++ main.o NodeObject.o Graph.o Finder.o -o output

main.o: main.cpp NodeObject.h Graph.h Finder.h
	g++ -c main.cpp

NodeObject.o: NodeObject.cpp NodeObject.h
	g++ -c NodeObject.cpp

Graph.o: Graph.cpp Graph.h NodeObject.h
	g++ -c Graph.cpp

Finder.o: Finder.cpp Finder.h Stack.h Queue.h PriorityQ.h
	g++ -c Finder.cpp

clean:
	rm *.o output 
