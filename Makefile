run: output
	./output

output: main.o NodeObject.o Graph.o Finder.o PriorityQ.o
	g++ main.o NodeObject.o Graph.o Finder.o PriorityQ.o -o output

valgrind: output
	valgrind -v --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./output

main.o: main.cpp NodeObject.h Graph.h Finder.h
	g++ -c -g main.cpp

NodeObject.o: NodeObject.cpp NodeObject.h
	g++ -c -g NodeObject.cpp

Graph.o: Graph.cpp Graph.h NodeObject.h
	g++ -c -g Graph.cpp

Finder.o: Finder.cpp Finder.h Stack.h Queue.h PriorityQ.o
	g++ -c -g Finder.cpp

PriorityQ.o: PriorityQ.cpp PriorityQ.h
	g++ -c -g PriorityQ.cpp

clean:
	rm *.o output 
	clear
