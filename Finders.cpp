#include "Finders.h"

Finders::Finders(Graph* grp){
    Finders::gr = grp;
}

std::vector<NodeObject*> Finders::breadthFirstSearch(NodeObject* start,NodeObject* target){  

    Finders::gr->setUnseen();
    Queue<NodeObject>* myQ = new Queue<NodeObject>();
    myQ->enqueue(start);
    start->setSeen(true);
    start->pathRecord = 0;

    while(!target->hasBeenSeen()){
        NodeObject* current = myQ->peek();
        std::vector<NodeObject*> curList = current->getChildren();
        std::vector<NodeObject*>::iterator i;
        for(i = curList.begin();i!=curList.end();++i){
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
        if((*i) != target)
            myQ->dequeue();
    }

    NodeObject* current = target;
    std::vector<NodeObject*> retVec;
    retVec.push_back(current);
    while(current!=start){
        current = current->lastVisited;
        retVec.push_back(current);
    }

    Finders::gr->setUnseen();
    
    return retVec;
}

std::vector<NodeObject*> Finders::depthFirstSearch(NodeObject* start,NodeObject* target){

    Stack<NodeObject>* myStack = new Stack<NodeObject>();
    Finders::gr->setUnseen();

    myStack->push(start);

    while(!target->hasBeenSeen()){
        NodeObject* current = myStack->peek();
        std::vector<NodeObject*> curList = current->getChildren();
        
        std::vector<NodeObject*>::iterator i;
        
        for(i = curList.begin();i!=curList.end();++i){
            if((*i)->hasBeenSeen())
                continue;
            else{
                (*i)->setSeen(true);
                (*i)->lastVisited = current;
                (*i)->pathRecord = current->pathRecord + current->getWeightOf(*i);
                if((*i) != target)
                    myStack->push(*i);

                break;                
            }
        }

        if(i == curList.end())
            myStack->pop();
    }

    NodeObject* current = target;
    std::vector<NodeObject*> retVec;
    retVec.push_back(current);
    while(current!=start){
        current = current->lastVisited;
        retVec.push_back(current);
    }

    Finders::gr->setUnseen();
    
    return retVec;

}

std::vector<NodeObject*> Finders::dijkstra(NodeObject* start,NodeObject* target){



}