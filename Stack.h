#include <cstdlib>

#ifndef STACK_H
#define STACK_H

template<class T>
class DTPTs{
    public:
        T* data;
        DTPTs* next;
        DTPTs(T *x){
            DTPTs::data = x;
            DTPTs::next = NULL;
        }
};

template <class T>
class Stack{
    public:
        Stack();
        T* pop();
        bool push(T*);
        T* peek();
        int size();
        bool empty();
        ~Stack();
    private:
        int count;
        DTPTs<T>* head;
};

#endif

