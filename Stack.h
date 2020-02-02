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
        Stack(){
            Stack::count = 0;
            Stack::head = NULL;
        }

        T* pop(){
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

        bool push(T* object){
            DTPTs<T>* temp = new DTPTs<T>(object);
            if(temp){
                temp->next = Stack::head;
                Stack::head = temp;
                return true;
            }
            else
                return false;
        }

        T* peek(){
            if(Stack::head)
                return Stack::head->data;
            else
                return NULL;
        }

        int size(){
            return Stack::count;
        }

        bool empty(){
            if(Stack::count == 0)
                return true;
            else
                return false;
        }

        ~Stack(){}
    private:
        int count;
        DTPTs<T>* head;
};

#endif

