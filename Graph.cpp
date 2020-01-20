#include "Graph.h"

Graph<class T>::Graph(){
    Graph::graphList = new std::vector<T*>();
    Graph::refList = new std::vector<int>();
    Graph::pathfinder = NULL;
}

Graph<class T>::Graph(std::vector<T*>*(*myAlg)(Graph*,T*,T*)){
    Graph::graphList = new std::vector<T*>();
    Graph::refList = new std::vector<int>();
    Graph::pathfinder = myAlg;
}

int Graph<class T>::getSize(){
    return Graph::graphList->size();
}

bool Graph<class T>::addNode(T *node,int id){

    for(std::vector<int>::iterator i = Graph::refList->begin();i!=Graph::refList->end();++i){
        if((*i)->getID() == id)
            return false;
    }


}

Graph<class T,class S>::~Graph(){
    delete graphList;
    delete refList;
}

