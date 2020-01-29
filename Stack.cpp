#include "Stack.h"
#include <cstdlib>

template<class T>

Stack<T>::Stack(){
    Stack::count = 0;
    Stack::head = NULL;
}

template<class T>
T* Stack<T>::pop(){
    DTPTs<T> * temp = Stack::head;
    
    if(temp){
        T* retVal = Stack::head->data;
        Stack::head = temp->next;
        Stack::count--;
        delete temp;
        return retVal;
    }
    else
        return NULL;
}

template<class T>
bool Stack<T>::push(T* object){
    DTPTs<T>* temp = new DTPTs<T>(object);
    if(temp){
        temp->next = Stack::head;
        Stack::head = temp;
        return true;
    }
    else
        return false;
}

template<class T>
T* Stack<T>::peek(){
    if(Stack::head)
        return Stack::head->data;
    else
        return NULL;
}

template<class T>
int Stack<T>::size(){
    return Stack::count;
}

template <class T>
bool Stack<T>::empty(){
    if(Stack::count == 0)
        return true;
    else
        return false;
}

template<class T>
Stack<T>::~Stack(){
    int i;

    for(i=0;i<Stack::count;i++)
        delete this->pop();
}