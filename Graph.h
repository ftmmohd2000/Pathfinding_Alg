#include <vector>
#include "NodeObject.h"
#ifndef MY_GRAPH
#define MY_GRAPH

class Graph{

    public:
        Graph(); //Default Constructor
        Graph(std::vector<NodeObject*> (*algo)(Graph*,NodeObject*,NodeObject*)); //Constructor given a pointer to a pathfinding algorithm
        std::vector<NodeObject*> (*pathfinder)(Graph*,NodeObject*,NodeObject*); //function pointer that can be used by user to point to different algorithms
        int getSize(); //returns number of nodes in graph
        bool addNode(NodeObject*,int); //Adding a node to a graph, returns false if the node ID already exists.
        bool removeNode(NodeObject*); //Removing a node from the graph in case of deletion, returns false if node doesn't exist in graph.
        void printGraph(); //Prints the values and connections contained by each node in the graph
        NodeObject* getNode(int); //Returns pointer to a specific node in the graph
        std::vector<NodeObject*> findPath(Graph*,NodeObject*,NodeObject*); //Returns a vector representing path found from start node to target node
        void printVec(std::vector<NodeObject*>);
        ~Graph(); //Destructor
    private:
        std::vector<int>* refList;
        std::vector<NodeObject*>* graphList; //Vector holding pointers to nodes in graph
        void setUnseen(); //Sets all Nodes to Seen value false.


};


#endif
