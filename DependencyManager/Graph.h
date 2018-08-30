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

class Graph {
public:
    Graph(vector<pair<char, char> > vertexPairs);
    vector<char> orderOfExecution();
    
    //  Development Only
    void printAdjacencyList();
    
private:
    
    struct vertex {
        char value;
        string status;
        vector<vertex*> neighbors;
    };
    
    void orderOfExecutionHelper(vector<char> &order, vertex* currentVertex);
    vector<vertex*> verticesAdjacentTo(char required_vertex);
    vector<vertex* > adjacencyList;
    
    int uniqueVertices;
    
};



#endif /* Graph_h */
