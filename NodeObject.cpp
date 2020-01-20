#include "NodeObject.h"
#include <vector>

NodeObject::NodeObject(int val){
    NodeObject::ID = val;
    NodeObject::nConnections = 0;
    NodeObject::seen = false;
}

int NodeObject::getID(){
    return NodeObject::ID;
}

bool NodeObject::hasBeenSeen(){
    return NodeObject::seen;
}

void NodeObject::setSeen(bool choice){
    NodeObject::seen = choice;
}

void NodeObject::joinTo(NodeObject *next){
    NodeObject::pointers.push_back(next);
    NodeObject::nConnections++;
}

bool NodeObject::removeCon(NodeObject* toBeGone){
   int i,size = NodeObject::pointers.size();

   for(i=0;i<size;i++)
        if(NodeObject::pointers.at(i) == toBeGone){
            NodeObject::pointers.erase(NodeObject::pointers.begin() + 1 + i);
            return true;
        }

    return false;        
}

std::vector<NodeObject*> NodeObject::getCons(){
    return NodeObject::pointers;
}

NodeObject::~NodeObject(){
}