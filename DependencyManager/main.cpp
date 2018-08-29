//
//  main.cpp
//  DependencyManager
//
//  Created by Jayant Mehra on 8/29/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<pair<char, char> > v;
    
    v.push_back(make_pair('1', '2'));
    v.push_back(make_pair('1', '3'));
    v.push_back(make_pair('1', '5'));
    
    Graph G(v);
    G.printAdjacencyList();
    
    vector<vertex*> x = G.verticesAdjacentTo('3');
    
    for (int i = 0; i < x.size(); i++)
        cout << x[i]->value << " ";
    cout << endl;
    
    vector<char> order = G.orderOfExecution();
    
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
   
    
    return 0;
}
