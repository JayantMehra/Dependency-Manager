//
//  Graph.cpp
//  DependencyManager
//
//  Created by Jayant Mehra on 8/29/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(vector<pair<char, char> > vertexPairs) {
    
    uniqueVertices = 0;
    size_t length = vertexPairs.size();
    
    for (size_t i = 0; i < length; i++) {
    
        vertex* parent = nullptr;
        vertex* child = nullptr;
        
        for (size_t j = 0; j < adjacencyList.size(); j++) {
            
            if (adjacencyList[j]->value == vertexPairs[i].first) {
                parent = adjacencyList[j];
            }
            
            if (adjacencyList[j]->value == vertexPairs[i].second) {
                child = adjacencyList[j];
            }
            
            if (parent != nullptr && child != nullptr)
                break;
        }
        
        if (parent == nullptr) {
            parent = new vertex;
            parent->value = vertexPairs[i].first;
            parent->status = "Inactive";
            adjacencyList.push_back(parent);
            uniqueVertices++;
        }
        
        if (child == nullptr) {
            child = new vertex;
            child->value = vertexPairs[i].second;
            child->status = "Inactive";
            adjacencyList.push_back(child);
            uniqueVertices++;
        }
        
        parent->neighbors.push_back(child);
    }
}

vector<Graph::vertex*> Graph::verticesAdjacentTo(char required_vertex) {
    
    vector<vertex*> temp;
    
    for (size_t i = 0; i < adjacencyList.size(); i++)
        if (adjacencyList[i]->value == required_vertex)
            return adjacencyList[i]->neighbors;
    
    return temp;
}

vector<char> Graph::orderOfExecution() {
    vector<char> order;
    
    
    for (size_t i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i]->status == "Inactive") {
            orderOfExecutionHelper(order, adjacencyList[i]);
        }
    }
    
    return order;
}

void Graph::orderOfExecutionHelper(vector<char> &order, vertex* currentVertex) {
   
    if (currentVertex == nullptr)
        return;
 
    currentVertex->status = "Active";
 
    vector<vertex*> adjacent = verticesAdjacentTo(currentVertex->value);
    
    
    for (size_t i = 0; i < adjacent.size(); i++) {
        if (adjacent[i]->status == "Inactive")
            orderOfExecutionHelper(order, adjacent[i]);
        
        else if (adjacent[i]->status == "Active") {
            cerr << "A cycle detected in the directed graph. Build Failed." << endl;
            exit(1);
        }
    }
    
    order.push_back(currentVertex->value);
    currentVertex->status = "Finished";

}

void Graph::printAdjacencyList() {
    
    for (size_t i = 0; i < adjacencyList.size(); i++) {
        vertex* temp = adjacencyList[i];
        cout << temp->value << "->";
        for (size_t i = 0; i < temp->neighbors.size(); i++)
            cout << temp->neighbors[i]->value << "->";
        cout << endl;
    }
    cout << "Unique Vertices: " << uniqueVertices << endl;
}
