#include "Finder.h"
#include <iostream>

Finder::Finder(Graph* grp){
    Finder::gr = grp;
}

std::vector<NodeObject*> Finder::breadthFirstSearch(NodeObject* start,NodeObject* target){  

    Finder::gr->setUnseen();//Clear Graph memory

    std::vector<NodeObject*> retVec;

    if(start == target){
        retVec.push_back(start);
        return retVec;
    }

    Queue<NodeObject>* myQ = new Queue<NodeObject>(); //Queue to be used for BFS

    myQ->enqueue(start); //Enqueue starting node
    start->setSeen(true);
    start->pathRecord = 0;

    while(target->hasBeenSeen() != true){
        
        NodeObject* current = myQ->peek();
     
        std::vector<NodeObject*> childList = current->getChildren();

        std::vector<NodeObject*>::iterator i;

        for(i = childList.begin();i!=childList.end();++i){
            if((*i)->hasBeenSeen())
                continue;
            else{
                (*i)->setSeen(true);
                (*i)->lastVisited = current;
                (*i)->pathRecord = current->pathRecord + current->getWeightOf((*i));
                myQ->enqueue((*i));
            }
        }
        myQ->dequeue();
    }

    NodeObject* current = target;
    retVec.push_back(current);
    while(current!=start){
        current = current->lastVisited;
        retVec.push_back(current);
    }
    
    return retVec;
}

std::vector<NodeObject*> Finder::depthFirstSearch(NodeObject* start,NodeObject* target){

    Stack<NodeObject>* myStack = new Stack<NodeObject>();
    Finder::gr->setUnseen();

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

    Finder::gr->setUnseen();
    
    return retVec;

}

std::vector<NodeObject*> Finder::dijkstra(NodeObject* start,NodeObject* target){
    Finder::gr->setUnseen();//Clear Graph memory

    std::vector<NodeObject*> retVec;

    if(start == target){
        retVec.push_back(start);
        return retVec;
    }

    PriorityQ* myQ = new PriorityQ(); //Queue to be used for BFS

    myQ->enqueue(start); //Enqueue starting node
    start->setSeen(true);
    start->pathRecord = 0;
    bool flag = true;
    while(flag){
        
        NodeObject* current = myQ->peek();
        
        if(current == target || myQ->empty())
            break;

        std::vector<NodeObject*> childList = current->getChildren();

        std::vector<NodeObject*>::iterator i;

        for(i = childList.begin();i!=childList.end();++i){
            int possible_cost = current->pathRecord + current->getWeightOf((*i));
            if((*i)->hasBeenSeen()){
                if((*i)->pathRecord > possible_cost){
                    (*i)->pathRecord = possible_cost;
                    (*i)->lastVisited = current;
                    myQ->enqueue((*i));
                }
            }
            else{
                (*i)->setSeen(true);
                (*i)->lastVisited = current;
                (*i)->pathRecord = possible_cost;
                myQ->enqueue((*i));
            }
        }

        myQ->dequeue();
    }

    NodeObject* current = target;
    retVec.push_back(current);
    while(current!=start){
        current = current->lastVisited;
        retVec.push_back(current);
    }
    
    return retVec;
}

void Finder::printStack(Stack<NodeObject> *ptr){

    Stack<NodeObject> copyStack = *ptr;
    int size = copyStack.size();
    for(int i = 0;i<size;i++){
        copyStack.peek()->getID();
        copyStack.pop();
    }

}

void Finder::printQ(Queue<NodeObject> *ptr){

    int size = ptr->size();
    for(int i = 0;i<size;i++){
        std::cout<< ptr->peek()->getID() << " ";
        ptr->enqueue(ptr->dequeue());
    }
    std::cout<<std::endl;
}