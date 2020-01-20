#include <vector>
#ifndef MY_NODE
#define MY_NODE

class NodeObject
{
    public:
        NodeObject(int id); //Constructor given a unique ID for the Node
        int getID(); //Gets the ID of the particular node.
        void setSeen(bool); //Sets the seen value to a given value
        bool hasBeenSeen(); //Returns seen value of the node
        void joinTo(NodeObject*); //Adds edge from current node to given node
        bool removeCon(NodeObject*);//removes an edge
        std::vector<NodeObject*> getCons();//Get all the edges outgoing from given node
        ~NodeObject();//Destructor

    private:
        int ID; 
        int nConnections; //Stores number of edges outgoing from node
        bool seen;
        std::vector<NodeObject*> pointers;
};

#endif