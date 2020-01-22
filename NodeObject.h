#include <vector>
#ifndef MY_NODE
#define MY_NODE

class NodeObject
{
    public:
        NodeObject(int); //Constructor given a unique ID for the Node
        int getID(); //Gets the ID of the particular node.
        void setSeen(bool); //Sets the seen value to a given value
        bool hasBeenSeen(); //Returns seen value of the node
        void addChild(NodeObject*); //Adds edge from current node to given node
        void removeChild(NodeObject*);//removes an edge
        void addParent(NodeObject*);
        void removeParent(NodeObject*);
        std::vector<NodeObject*> getChildren();//Get all the edges outgoing from given node
        std::vector<NodeObject*> getParents();//Get all the edges outgoing from given node
        ~NodeObject();//Destructor

    private:
        int ID; 
        int nChildren; //Stores number of edges outgoing from node
        int nParents;
        bool seen;
        std::vector<NodeObject*> children;
        std::vector<NodeObject*> parents;
};

#endif