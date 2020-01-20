#include <iostream>
#include "NodeObject.h"
#include "Graph.h"

int main(){
    NodeObject myNode1(5);
    myNode1.setSeen(true);
    Graph *myGraph = new Graph();

    myGraph->printGraph();
    
    myGraph->addNode(&myNode1,myNode1.getID());
    NodeObject myNode2(89);
    myNode2.joinTo(&myNode1);

    myGraph->addNode(&myNode2,myNode2.getID());

    myGraph->printGraph();

    //myGraph->removeNode(&myNode2);

    myGraph->printGraph();
    //std::cout << myNode1.hasBeenSeen() << std::endl;

    return 0;
}