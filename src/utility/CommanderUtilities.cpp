#include <list>
#include <algorithm>
#include "../include/GraphUtilities.hpp"
#include <iostream>

using namespace std;

int Order(int v, Graph alterGraph)
{
	bool *visited = new bool[alterGraph.V]; 
    list<int> queue;
    list<int> neighbor;
    for(int i = 0; i < alterGraph.V; i++)
        visited[i] = false;     

    visited[v] = true;
        
    queue.push_back(v); 
    
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    {   
        v = queue.front();        
        queue.remove(v);
          
        for (i = alterGraph.adj[v].begin(); i != alterGraph.adj[v].end(); ++i) 
        { 
            if (!visited[*i])   
            {				
                visited[*i] = true;                                            
				neighbor.push_back(*i);
                queue.push_back(*i);                 
            }          
        }
              
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