#include "NodeObject.h"
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

#ifndef FINDERS_H
#define FINDERS_H

class Finders{
    public:
        Finders(Graph*);
        std::vector<NodeObject*> breadthFirstSearch(NodeObject*,NodeObject*);
        std::vector<NodeObject*> depthFirstSearch(NodeObject*,NodeObject*);
        std::vector<NodeObject*> dijkstra(NodeObject*,NodeObject*);
    private:
        Graph* gr;
};

#endif