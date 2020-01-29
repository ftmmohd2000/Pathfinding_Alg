#include "Stack.h"
#include "Queue.h"
#include "Finders.h"
#include "NodeObject.h"
#include "Graph.h"

std::vector<NodeObject*> Finders::breadthFirstSearch(Graph* gr,NodeObject* start,NodeObject* target){  

    gr->setUnseen();
    Queue<NodeObject>* myQ = new Queue<NodeObject>();
    myQ->enqueue(start);
    start->setSeen(true);
    start->pathRecord = 0;

    while(!target->hasBeenSeen()){
        NodeObject* current = myQ->peek();
        std::vector<NodeObject*> curList = current->getChildren();
        for(std::vector<NodeObject*>::iterator i = curList.begin();i!=curList.end();++i){
            if(!(*i)->hasBeenSeen()){
                (*i)->setSeen(true);
                (*i)->pathRecord = current->pathRecord + current->getWeightOf(*i);
                (*i)->lastVisited = current;
                if((*i) == target)
                    break;
                else
                    myQ->enqueue(*i);
            }
        }
    }

    NodeObject* current = target;
    std::vector<NodeObject*> retVec;
    retVec.push_back(current);
    while(current!=start){
        current = current->lastVisited;
        retVec.push_back(current);
    }

    gr->setUnseen();
    
    return retVec;
}

std::vector<NodeObject*> Finders::depthFirstSearch(Graph* gr,NodeObject* start,NodeObject* target){



}

std::vector<NodeObject*> Finders::dijkstra(Graph* gr,NodeObject* start,NodeObject* target){



}