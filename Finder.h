#include "NodeObject.h"
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQ.h"

#ifndef FINDERS_H
#define FINDERS_H

class Finder{
    public:
        Finder(Graph*);
        std::vector<NodeObject*> breadthFirstSearch(NodeObject*,NodeObject*);
        std::vector<NodeObject*> depthFirstSearch(NodeObject*,NodeObject*);
        std::vector<NodeObject*> dijkstra(NodeObject*,NodeObject*);
        void printStack(Stack<NodeObject>*);
        void printQ(Queue<NodeObject>*);
    private:
        Graph* gr;
};

#endif