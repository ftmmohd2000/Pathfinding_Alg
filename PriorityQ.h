#include "Queue.h"
#include "NodeObject.h"

#ifndef PRIORITYQ_H
#define PRIORITYQ_H

class PriorityQ{                        //implements a heap
    public:
        PriorityQ();
        PriorityQ(int);
        bool enqueue(NodeObject*);
        NodeObject* dequeue();
        NodeObject* peek();
        bool empty();
        int size();
        int getMax();
        void printQ();
    private:
        int currSize;
        int maxSize;
        NodeObject** heap;
        void reHeapDown(int);
        void reHeapUp(int);
        void switchNode(int,int);
};

#endif