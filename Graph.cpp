#include <iostream>
#include "Graph.h"
#include "NodeObject.h"
#include <fstream>

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

void Graph::addNode(int id){

    NodeObject* newNode = new NodeObject(id);

    for(std::vector<int>::iterator i = Graph::refList->begin();i!=Graph::refList->end();++i)
        if((*i) == id){
            delete newNode;
            return;
        }

    Graph::refList->push_back(id);
    Graph::graphList->push_back(newNode);
}

void Graph::removeNode(NodeObject *node){

    int id = node->getID();
    std::vector<NodeObject*>::iterator i,j;
    bool flag;

    for(i = Graph::graphList->begin();i!=Graph::graphList->end();++i)
        if(*i == node){
            flag = true;
            break;
        }

    if (flag){

        std::vector<NodeObject*> temp = node->getParents();

        for(j = temp.begin();j!=temp.end();++j)
            (*j)->removeChild(node);

        temp = node->getChildren();

        for(j = temp.begin();j!=temp.end();++j)
            (*j)->removeParent(node);

        Graph::graphList->erase(i);

        delete node;
    }
    else
        return;

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

void Graph::addEdge(NodeObject* parent, NodeObject* child,int weight){
    parent->addChild(child,weight);
    child->addParent(parent);
}

void Graph::removeEdge(NodeObject* parent, NodeObject* child){
    parent->removeChild(child);
    child->removeParent(parent);
}

void Graph::printGraph(){

    std::vector<NodeObject*> tempArr;

    for(std::vector<NodeObject*>::iterator i = Graph::graphList->begin();i!=Graph::graphList->end();++i){
        tempArr = ((*i)->getChildren());

        std::cout<<"Node ID "<<(*i)->getID()<<" connects to: ";

        for(std::vector<NodeObject*>::iterator j = tempArr.begin();j!=tempArr.end();++j){
            std::cout<<(*j)->getID();
            std::cout<<"("<<(*i)->getWeightOf(*j)<<") ";
        }
        
        std::cout<<std::endl;
    }
}

void Graph::printVec(std::vector<NodeObject*> myVec){
    std::cout<<"**********";

    for(std::vector<NodeObject*>::iterator i = myVec.begin();i!=myVec.end();++i)
        std::cout<<(*i)->getID()<<" ";

    std::cout<<"**********"<<std::endl;
}

void Graph::setUnseen(){
    std::vector<NodeObject*>::iterator i;

    for(i=Graph::graphList->begin();i!=Graph::graphList->end();++i){
        (*i)->setSeen(false);
        (*i)->clearRecord();
    }
}

void Graph::writeToFile(){
    std::vector<NodeObject*>::iterator i,j;
    std::ofstream fptr;
    
    fptr.open("existing.txt");
    for(i=Graph::graphList->begin();i!=Graph::graphList->end();++i){
        fptr << (*i)->getID();
        std::vector<NodeObject*> tempAr = (*i)->getChildren();
        for(j = tempAr.begin();j!=tempAr.end();++j){
            fptr << " " << (*j)->getID();
            fptr << " " << (*i)->getWeightOf(*j);
        }
        fptr << std::endl;
    }
}

Graph::~Graph(){
    delete graphList;
    delete refList;
}
