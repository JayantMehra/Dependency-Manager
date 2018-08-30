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
    
    v.push_back(make_pair('d', 'a'));
    v.push_back(make_pair('b', 'f'));
    v.push_back(make_pair('d', 'b'));
    v.push_back(make_pair('a', 'f'));
    v.push_back(make_pair('c', 'd'));
    
    Graph G(v);
    G.printAdjacencyList();
    vector<char> order = G.orderOfExecution();
    
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
   
    
    return 0;
}
