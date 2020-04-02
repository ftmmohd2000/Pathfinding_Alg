#include "PriorityQ.h"
#include "NodeObject.h"
#include <stdio.h>

PriorityQ::PriorityQ(){
    PriorityQ::maxSize = 100;
    PriorityQ::currSize = 0;
    PriorityQ::heap = (NodeObject**)malloc(sizeof(NodeObject*)*maxSize);
    for(int i = 0;i<maxSize;i++)
        PriorityQ::heap[i] = NULL;
}

PriorityQ::PriorityQ(int max){
    PriorityQ::maxSize = max;
    PriorityQ::currSize = 0;
    PriorityQ::heap = (NodeObject**)malloc(sizeof(NodeObject*)*maxSize);
    for(int i = 0;i<maxSize;i++)
        PriorityQ::heap[i] = NULL;
}

bool PriorityQ::enqueue(NodeObject* newNode){
    
    if(currSize >= maxSize)
        return false;

    PriorityQ::heap[currSize] = newNode;
    PriorityQ::currSize++;  
    this->reHeapUp(currSize-1);
    return true;
}

NodeObject* PriorityQ::dequeue(){

    if(this->empty())
        return NULL;

    this->switchNode(0,currSize-1);
    PriorityQ::currSize--;
    this->reHeapDown(0);
    return PriorityQ::heap[currSize];
}

NodeObject* PriorityQ::peek(){
    if(this->empty())
        return NULL;
    else
        return PriorityQ::heap[0];
}

bool PriorityQ::empty(){
    if(currSize == 0)
        return true;
    else
        return false;
}

int PriorityQ::size(){
    return PriorityQ::currSize;
}

int PriorityQ::getMax(){
    return PriorityQ::maxSize;
}

void PriorityQ::reHeapDown(int target){

    while(true){
        int left = target*2+1;
        int right = target*2+2;
        int numChild = 0;
        if(left < PriorityQ::currSize){
            if(right<PriorityQ::currSize)
                numChild = 2;
            else
                numChild = 1;
        }
        if(numChild == 1){
            if(PriorityQ::heap[target]->pathRecord > PriorityQ::heap[left]->pathRecord)
                {
                    this->switchNode(target,left);
                    return;
                }
                else
                    return;
        }
        else if(numChild == 2){
            if(PriorityQ::heap[left]->pathRecord < PriorityQ::heap[right]->pathRecord)
            {
                if(PriorityQ::heap[left]->pathRecord < PriorityQ::heap[target]->pathRecord)
                {
                    this->switchNode(left,target);
                    target = left;
                    continue;
                }
                else
                    return;
            }
            else{
                if(PriorityQ::heap[right]->pathRecord < PriorityQ::heap[target]->pathRecord)
                {
                    this->switchNode(right,target);
                    target = right;
                    continue;
                }
                else
                    return;
            }
        }
        else
            return;
    }

}

void PriorityQ::reHeapUp(int target){
    
    while(true){
        if(target != 0 && (PriorityQ::heap[target]->pathRecord < PriorityQ::heap[(target-1)/2]->pathRecord)){
            this->switchNode(target,(target-1)/2);
            target = (target-1) / 2;
        }
        else
            break;
    }

}

void PriorityQ::switchNode(int a,int b){
    NodeObject* temp = PriorityQ::heap[a];
    PriorityQ::heap[a] = PriorityQ::heap[b];
    PriorityQ::heap[b] = temp;
}

void PriorityQ::printQ(){

    printf("[ ");

    for(int i=0;i<PriorityQ::currSize;i++)
        printf("%d ",PriorityQ::heap[i]->pathRecord);

    printf("]\n");
}
