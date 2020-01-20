#include <vector>
#ifndef MY_GRAPH
#define MY_GRAPH

template<class T> // S is the data element stored by the class T
class Graph{

    public:
        Graph(); //Default Constructor
        Graph(std::vector<T*>*(*algo)(Graph*,T*,T*)); //Constructor given a pointer to a pathfinding algorithm
        std::vector<T*>*(*pathfinder)(Graph*,T*,T*); //function pointer that can be used by user to point to different algorithms
        int getSize(); //returns number fo nodes in graph
        bool addNode(T*,int); //Adding a node to a graph, returns false if the node ID already exists.
        bool removeNode(T*); //Removing a node from the graph in case of deletion, returns false if node doesn't exist in graph.
        void printGraph(); //Prints the values and connections contained by each node in the graph
        T* getNode(int); //Returns pointer to a specific node in the graph
        std::vector<T*> findPath(Graph*,T*,T*); //Returns a vector representing path found from start node to target node
        ~Graph(); //Destructor
    private:
        std::vector<int>* refList;
        std::vector<T*>* graphList; //Vector holding pointers to nodes in graph
        void setUnseen(); //Sets all Nodes to Seen value false.


};


#endif
