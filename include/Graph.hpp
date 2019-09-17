#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <string>

using namespace std;

class Graph 
{ 
    public: 
        int V;
	    list<int>* adj;
        list<map<string, list<int>>> commands;
	    map<int, int> ages;
        Graph();
        void Create(int V);
	    void AddEdge(int v1, int v2);        
        bool HasCycle();
        bool Dfs(int v, bool visited[], bool recStack[]);
        void Alter(list<map<string, list<int>>> commands, map<int, int> ages);
        void Print(int v, bool visited[], string *row);
}; 

#endif