#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "../include/GraphUtilities.hpp"
#include "../include/SwapUtilities.hpp"

using namespace std;

void Swap(Graph graph, list<int> items, string *fileOut)
{	
	bool isSwap = GetSwap(graph, items);	

	if(isSwap)	
		*fileOut += "S T\n";
	else	
		*fileOut += "S N\n";
}

void Commander(Graph graph)
{
	//printf("Commander\n");
}

void Meeting(Graph graph, string *fileOut)
{
	string row = "";
	graph.Bfs(0, &row);
	*fileOut += row + "\n";
}

void Tasks(Graph graph)
{
	string fileOut = "";
	typedef map <string, list<int>> StringFloatMap;
	StringFloatMap :: iterator pos;	

	for (auto i: graph.commands) 
	{
		for (pos = i.begin(); pos != i.end (); ++ pos) 
		{
			string command = pos->first;
			list<int> items = pos->second;		

			if(command == "S")
				Swap(graph, items, &fileOut);
			else if(command == "C")
				Commander(graph);
			else if(command == "M")
				Meeting(graph, &fileOut);
			else
			{
				cout << "Comando " << command << " inválido";
			}
		}
	}
	
	cout << fileOut;	
}

void StartTP1(string equipeFile)
{
	Graph graph = GetGraphFromFile(equipeFile);
	Tasks(graph);
}