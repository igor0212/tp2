#include <list>
#include <algorithm>
#include "../include/GraphUtilities.hpp"
#include <iostream>

using namespace std;

void OrderUtil(int v, bool visited[], Graph alterGraph, list<int> *neighbor, list<int> *all) 
{ 
    visited[v] = true; 
	all->remove(v);
    
    list<int>::iterator i; 
    for (i = alterGraph.adj[v].begin(); i != alterGraph.adj[v].end(); ++i) 
	{	
        if (!visited[*i]) 
		{
			neighbor->push_back(*i);
			OrderUtil(*i, visited, alterGraph, neighbor, all); 
		}            
	}
}   

int Order(int v, Graph alterGraph) 
{   
    bool *visited = new bool[alterGraph.V]; 
	list<int> all, neighbor;     	
    for (int i = 0; i < alterGraph.V; i++) 	
	{
		all.push_back(i);
		visited[i] = false;   
	}

	while(!all.empty())    
    {	
		int s;
		if(all.size() == alterGraph.V)
			s = v;
		else		
			s = all.front();						
		
    	OrderUtil(s, visited, alterGraph, &neighbor, &all); 
	}

	int age;

	if(neighbor.empty())
		age = -1;
	else {
		neighbor.sort();
		age = alterGraph.ages[neighbor.front()];
	}

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