#include "NodeObject.h"
#include "Graph.h"

#ifndef FINDERS_H
#define FINDERS_H

class Finders{
    public:

        static std::vector<NodeObject*> breadthFirstSearch(Graph*,NodeObject*,NodeObject*);
        static std::vector<NodeObject*> depthFirstSearch(Graph*,NodeObject*,NodeObject*);
        static std::vector<NodeObject*> dijkstra(Graph*,NodeObject*,NodeObject*);
    
};

#endif