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
        Queue();
        T* dequeue();
        T* peek();
        bool enqueue(T*);
        int size();
        bool empty();
        ~Queue();
    private:
        int count;
        DTPT<T> *head;
        DTPT<T> *tail;
    
};

#endif