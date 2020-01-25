#include <vector>
#include "NodeObject.h"
#ifndef MY_GRAPH
#define MY_GRAPH

class Graph{

    public:
        Graph(); //Default Constructor
        Graph(std::vector<NodeObject*> (*algo)(Graph*,NodeObject*,NodeObject*)); //Constructor given a pointer to a pathfinding algorithm
        int getSize(); //returns number of nodes in graph
        void addNode(int); //Adding a node to a graph, returns false if the node ID already exists.
        void removeNode(NodeObject*); //Removing a node from the graph in case of deletion, returns false if node doesn't exist in graph.
        NodeObject* getNode(int); //Returns pointer to a specific node in the graph
        void addEdge(NodeObject*,NodeObject*);
        void removeEdge(NodeObject*,NodeObject*);       
        void printGraph(); //Prints the values and connections contained by each node in the graph
        void printVec(std::vector<NodeObject*>);
        void setUnseen(); //Sets all Nodes to Seen value false.
        void writeToFile();
        ~Graph(); //Destructor
        std::vector<NodeObject*> (*pathfinder)(Graph*,NodeObject*,NodeObject*); //function pointer that can be used by user to point to different algorithms
        std::vector<NodeObject*> findPath(Graph*,NodeObject*,NodeObject*); //Returns a vector representing path found from start node to target node
    private:
        std::vector<int>* refList;
        std::vector<NodeObject*>* graphList; //Vector holding pointers to nodes in graph

};


#endif
