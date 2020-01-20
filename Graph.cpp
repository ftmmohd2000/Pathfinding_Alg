#include <iostream>
#include "Graph.h"
#include "NodeObject.h"

Graph::Graph(){
    Graph::graphList = new std::vector<NodeObject*>();
    Graph::refList = new std::vector<int>();
    Graph::pathfinder = NULL;
}

Graph::Graph(std::vector<NodeObject*>(*myAlg)(Graph*,NodeObject*,NodeObject*)){
    Graph::graphList = new std::vector<NodeObject*>();
    Graph::refList = new std::vector<int>();
    Graph::pathfinder = myAlg;
}

int Graph::getSize(){
    return Graph::graphList->size();
}

bool Graph::addNode(NodeObject *node,int id){

    for(std::vector<int>::iterator i = Graph::refList->begin();i!=Graph::refList->end();++i){
        if((*i) == id)
            return false;
    }

    Graph::refList->push_back(id);
    Graph::graphList->push_back(node);

    return true;
}

bool Graph::removeNode(NodeObject *node){

    int id = node->getID();

    for(std::vector<NodeObject*>::iterator i = Graph::graphList->begin();i!=Graph::graphList->end();++i){
        if(*i == node){
            Graph::graphList->erase(i);
            break;
        }
    }
    for(std::vector<int>::iterator i = Graph::refList->begin();i!=Graph::refList->end();++i){
        if(*i == id){
            Graph::refList->erase(i);
            return true;
        }
    }

    return false;
}

void Graph::printGraph(){

    std::vector<NodeObject*> tempArr;

    for(std::vector<NodeObject*>::iterator i = Graph::graphList->begin();i!=Graph::graphList->end();++i){
        tempArr = ((*i)->getCons());

        std::cout<<"Node ID "<<(*i)->getID()<<" connects to: ";

        for(std::vector<NodeObject*>::iterator j = tempArr.begin();j!=tempArr.end();++j)
            std::cout<<(*j)->getID()<<" ";
        
        std::cout<<std::endl;
    }
}

NodeObject* Graph::getNode(int id){
    for(std::vector<NodeObject*>::iterator i = Graph::graphList->begin();i!=Graph::graphList->end();++i){
        if((*i)->getID() == id)
            return *i;
    }

    return NULL;
}

std::vector<NodeObject*> Graph::findPath(Graph *g,NodeObject *start, NodeObject *target){
    return Graph::pathfinder(g,start,target);
}


void Graph::printVec(std::vector<NodeObject*> myVec){
    std::cout<<"**********";

    for(std::vector<NodeObject*>::iterator i = myVec.begin();i!=myVec.end();++i)
        std::cout<<(*i)->getID()<<" ";

    std::cout<<"**********"<<std::endl;
}

Graph::~Graph(){
    delete graphList;
    delete refList;
}

