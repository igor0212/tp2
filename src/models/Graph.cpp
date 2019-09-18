#include <list>
#include <string>
#include <map>
#include ".\Graph.hpp"
#include <iostream>
#include<iostream> 
#include <sstream> 

using namespace std;

Graph::Graph(){}

void Graph::Create(int V)
{
	this->V = V;
	adj = new list<int>[V];	
}

void Graph::Alter(list<map<string, list<int>>> commands, map<int, int> ages)
{
	this->commands = commands;
	this->ages = ages;
}

void Graph::AddEdge(int v1, int v2)
{	
	adj[v1].push_back(v2);
}

bool Graph::HasCycle()
{ 
	bool result = false;
    bool *visited = new bool[V]; 
	bool *recStack = new bool[V]; 
    for (int i = 0; i < V; i++) 
	{
        visited[i] = false;
		recStack[i] = false; 
	}

    if(Dfs(0, visited, recStack))
		result = true;
	
	return result;
} 

bool Graph::Dfs(int v, bool visited[], bool recStack[]) 
{ 
    visited[v] = true;
	recStack[v] = true;	
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	{
		if (!visited[*i] && Dfs(*i, visited, recStack)) 
            return true;
		else if (recStack[*i])
			return true;
	}

	recStack[v] = false;
	return false;
}

void Graph::Bfs(int s, string *row) 
{   
    bool *visited = new bool[V]; 
    list<int> queue;
    list<int> all; 
    for(int i = 0; i < V; i++)
    {
        all.push_back(i);
        visited[i] = false; 
    }

    visited[s] = true;
        
    queue.push_back(s); 
    
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    {   
        s = queue.front();
        visited[s] = true;   
		ostringstream str_s; 
		str_s << s+1; 
		*row += str_s.str() + " ";	
        queue.remove(s);         
        all.remove(s);    
          
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i])   
            {
                visited[*i] = true;                                            
                queue.push_back(*i);                 
            }          
        }         

        if(queue.empty() && !all.empty())                 
            queue = all;            
    }
} 