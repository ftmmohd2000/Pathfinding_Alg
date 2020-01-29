#include "Queue.h"
#include <cstdlib>

template<class T>
Queue<T>::Queue(){
    Queue::count = 0;
    Queue::head = NULL;
    Queue::tail = NULL;
}

template<class T>
T* Queue<T>::dequeue(){
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

template<class T>
T* Queue<T>::peek(){
    return Queue::head->data;
}

template<class T>
bool Queue<T>::enqueue(T* object){

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

template<class T>
int Queue<T>::size(){
    return Queue::count;
}

template<class T>
bool Queue<T>::empty(){
    if(Queue::count == 0)
        return true;
    else
        return false;
}

template<class T>
Queue<T>::~Queue(){
    for(int i = 0;i<Queue::count;i++)
        delete this->dequeue();
}