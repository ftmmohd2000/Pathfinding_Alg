#include <cstdlib>

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class DTPT{
        public:
            T* data;
            DTPT *next;
            DTPT *prev;
            DTPT(T *x){
                DTPT::data = x;
                DTPT::next = NULL;
                DTPT::prev = NULL;
        }
    };

template <class T>
class Queue{

    public:
        Queue(){
            Queue::count = 0;
            Queue::head = NULL;
            Queue::tail = NULL;
        }
        T* dequeue(){
            if(Queue::count == 0)
            return NULL;
        
            T* retVal = Queue::head->data;
            DTPT<T>* temp = Queue::head;
            Queue::head = Queue::head->next;
            if(Queue::count == 1)
                Queue::tail = NULL;
            else
                Queue::head->prev = NULL;
            
            Queue::count--;
            delete temp;

            return retVal;
        }
        T* peek(){
            return Queue::head->data;
        }
        bool enqueue(T* object){
    
            DTPT<T>* newNode = new DTPT<T>(object);
    
            if(!newNode)
                return false;
            
            newNode->next = NULL;
            newNode->prev = Queue::tail;
            Queue::tail = newNode;
            
            if(Queue::count == 0)
                Queue::head = newNode;
            else
                newNode->prev->next = newNode;
            Queue::count++;

            return true;
        }
        int size(){
            return Queue::count;
        }
        bool empty(){
        
        if(Queue::count == 0)
            return true;
        else
            return false;
        
        }
        ~Queue(){}
    protected:
        int count;
        DTPT<T> *head;
        DTPT<T> *tail;
    
};

#endif