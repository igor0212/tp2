#include <list>
#include <algorithm>
#include "../include/GraphUtilities.hpp"
#include <iostream>

using namespace std;

void OrderUtil(int v, bool visited[], Graph alterGraph, list<int> *all) 
{ 
    visited[v] = true; 
    
    list<int>::iterator i; 
    for (i = alterGraph.adj[v].begin(); i != alterGraph.adj[v].end(); ++i) 
	{		
		all->push_back(*i);
        if (!visited[*i]) 
            OrderUtil(*i, visited, alterGraph, all); 
	}
}   

int Order(int v, Graph alterGraph) 
{   
    bool *visited = new bool[alterGraph.V]; 
	list<int> all;     
    for (int i = 0; i < alterGraph.V; i++) 	
		visited[i] = false;   
	
    OrderUtil(v, visited, alterGraph, &all); 

	all.sort();

	int age = alterGraph.ages[all.front()];

	return age;
} 

int GetCommander(Graph graph, list<int> items)
{	
	if(items.empty())
		return -1;	

	int item1 = items.front();
	Graph alterGraph = graph.GetTranspose();	

	return Order(item1, alterGraph);
}