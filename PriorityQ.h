#include "Queue.h"
#include "NodeObject.h"

#ifndef PRIORITYQ_H
#define PRIORITYQ_H

class PriorityQ: public Queue<NodeObject>{

    public:
        bool enqueue(NodeObject* object){
            DTPT<NodeObject>* newNode = new DTPT<NodeObject>(object);
    
            if(!newNode)
                return false;
            
            if(PriorityQ::count == 0){
                PriorityQ::head = newNode;
                PriorityQ::tail = newNode;
                newNode->next = newNode->prev = NULL;
                PriorityQ::count++;
                return true;
            }
            else if(newNode->data->pathRecord < PriorityQ::head->data->pathRecord){
                PriorityQ::head->prev = newNode;
                newNode->next = PriorityQ::head;
                newNode->prev = NULL;
                PriorityQ::head = newNode;
                PriorityQ::count++;
                return true;
            }
            else if(newNode->data->pathRecord > PriorityQ::tail->data->pathRecord){
                PriorityQ::tail->next = newNode;
                newNode->prev = PriorityQ::tail;
                newNode->next = NULL;
                PriorityQ::tail = newNode;
                PriorityQ::count++;
                return true;
            }
            else{
                DTPT<NodeObject>* current = PriorityQ::tail;

                while(current->data->pathRecord > newNode->data->pathRecord)
                    current = current->prev;

                //perform the insertion
                newNode->next = current->next;
                current->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev = current;

                PriorityQ::count++;

                return true;
            }
        }

};

#endif