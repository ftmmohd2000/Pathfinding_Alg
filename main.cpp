#include <iostream>
#include "NodeObject.h"
#include "Graph.h"

int main(){
    NodeObject myNode1(5);
    myNode1.setSeen(true);
    Graph<NodeObject,int> mygraph;
    std::cout << myNode1.hasBeenSeen() << std::endl;

    return 0;
}