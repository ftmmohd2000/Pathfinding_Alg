#include <iostream>
#include "NodeObject.h"
#include "Graph.h"

void print_menu();
int get_choice();
void do_job(int,Graph*);
void myAddNode(Graph*);
void myRemoveNode(Graph*);
void myAddEdge(Graph*);
void myRemoveEdge(Graph*);

int main(){

    Graph *graph = new Graph();

    int input = 100;

    while(input != 0){
        print_menu();
        input = get_choice();
        do_job(input, graph);
    }

    delete graph;

    return 0;
}

void print_menu(){
    std::cout << "Here are your choices:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1) Add a new Node" << std::endl;
    std::cout << "2) Remove an existing node" << std::endl;
    std::cout << "3) Add a new edge" << std::endl;
    std::cout << "4) Remove an existing edge" << std::endl;
    std::cout << "5) Print the current graph state" << std::endl;
    std::cout << "   Press '0' to exit" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Enter choice: " << std::endl;
}

int get_choice(){
    int user_in;

    std::cin >> user_in;

    while(user_in > 5 || user_in < 0){
        std::cout << "Wrong Choice. Enter a number from 1 to 5. 0 to exit: ";
        std::cin >> user_in;
    }

    return user_in;
}

void do_job(int choice,Graph* graph){

    int temp;

    switch (choice){
        case 0: return;
        case 1: myAddNode(graph);
                return;
        case 2: myRemoveNode(graph);
                return;
        case 3: myAddEdge(graph);
                return;
        case 4: myRemoveEdge(graph);
                return;
        case 5: graph->printGraph();
                return;
    }

}

void myAddNode(Graph* graph){
    
    int input;
    
    std::cout << "Please enter new node ID: ";
    std::cin >> input;

    if(graph->getNode(input))
        return;
    else
        graph->addNode(input);
}

void myRemoveNode(Graph* graph){

    int input;
    NodeObject* temp;

    std::cout << "Please enter node ID to be removed: ";
    std::cin >> input;

    temp = graph->getNode(input);

    if(temp)
        graph->removeNode(temp);
    else
        return;
}

void myAddEdge(Graph* graph){

    int in1,in2;
    NodeObject *pr,*ch;

    std::cout << "Enter node ID of parent node: ";
    std::cin >> in1;
    std::cout << "Enter node ID of child node: ";
    std::cin >> in2;

    pr = graph->getNode(in1);
    ch = graph->getNode(in2);

    if(!pr || !ch){
        std::cout << "One or more members invalid" << std::endl;
        return;
    }
    else
        graph->addEdge(pr,ch);

}

void myRemoveEdge(Graph* graph){

    int in1,in2;
    NodeObject *pr,*ch;

    std::cout << "Enter node ID of parent node: ";
    std::cin >> in1;
    std::cout << "Enter node ID of child node: ";
    std::cin >> in2;

    pr = graph->getNode(in1);
    ch = graph->getNode(in2);

    if(!pr || !ch){
        std::cout << "One or more members invalid" << std::endl;
        return;
    }
    else
        graph->removeEdge(pr,ch);

}