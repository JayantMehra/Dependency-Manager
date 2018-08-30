//
//  Graph.h
//  DependencyManager
//
//  Created by Jayant Mehra on 8/29/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <vector>
#include <string>
using namespace std;

struct vertex {
    char value;
    string status;
    vector<vertex*> neighbors;
};

class Graph {
public:
    Graph(vector<pair<char, char> > vertexPairs);
    vector<char> orderOfExecution();
    vector<vertex*> verticesAdjacentTo(char required_vertex);
    
    //  Development Only
    void printAdjacencyList();
    
private:
    void orderOfExecutionHelper(vector<char> &order, vertex* currentVertex);
    
    vector<vertex* > adjacencyList;
    int uniqueVertices;
    
};



#endif /* Graph_h */
