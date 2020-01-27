#include "NodeObject.h"
#include <vector>

NodeObject::NodeObject(int val){
    NodeObject::ID = val;
    NodeObject::nChildren = 0;
    NodeObject::nParents = 0;
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

void NodeObject::addChild(NodeObject *newChild,int weight){

    for(int i = 0;i<NodeObject::children.size();i++)
        if(NodeObject::children.at(i) == newChild)
            return;
        

    NodeObject::children.push_back(newChild);
    NodeObject::weights.push_back(weight);
    newChild->addParent(this);
    NodeObject::nChildren++;
}

void NodeObject::removeChild(NodeObject* toBeGone){
   
    std::vector<NodeObject*>::iterator i;

   for(i=NodeObject::children.begin();i!=NodeObject::children.end();++i)
        if(*i == toBeGone){
            NodeObject::children.erase(i);
            NodeObject::nChildren--;
            return;
        }
}

void NodeObject::addParent(NodeObject* newParent){

    for(int i = 0;i<NodeObject::parents.size();i++)
        if(NodeObject::parents.at(i) == newParent)
            return;
        

    NodeObject::parents.push_back(newParent);
    newParent->addParent(this);
    NodeObject::nParents++;
}

void NodeObject::removeParent(NodeObject* toBeGone){
    
    std::vector<NodeObject*>::iterator i;
    
    for(i = NodeObject::parents.begin();i!=NodeObject::parents.end();++i)
        if(*i == toBeGone){
            NodeObject::parents.erase(i);
            NodeObject::nParents--;
            return;
        }
}

int NodeObject::getWeightOf(NodeObject* target){

    int i;
    int size = NodeObject::children.size();

    for(i=0;i<size;i++)
        if(target == NodeObject::children[i])
            break;

    return NodeObject::weights[i];

}

std::vector<NodeObject*> NodeObject::getChildren(){
    return NodeObject::children;
}

std::vector<NodeObject*> NodeObject::getParents(){
    return NodeObject::parents;
}

NodeObject::~NodeObject(){
}