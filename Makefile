run: output
	./output

output: main.o NodeObject.o Graph.o Finder.o PriorityQ.o
	g++ main.o NodeObject.o Graph.o Finder.o PriorityQ.o -o output

main.o: main.cpp NodeObject.h Graph.h Finder.h
	g++ -c main.cpp

NodeObject.o: NodeObject.cpp NodeObject.h
	g++ -c NodeObject.cpp

Graph.o: Graph.cpp Graph.h NodeObject.h
	g++ -c Graph.cpp

Finder.o: Finder.cpp Finder.h Stack.h Queue.h PriorityQ.o
	g++ -c Finder.cpp

PriorityQ.o: PriorityQ.cpp PriorityQ.h
	g++ -c PriorityQ.cpp

clean:
	rm *.o output 
	clear
