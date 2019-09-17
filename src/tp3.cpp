#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "../include/GraphUtilities.hpp"

using namespace std;

void PrintCommands(Graph graph)
{
	typedef map <string, list<int>> StringFloatMap;
	StringFloatMap :: iterator pos;

	for (auto i: graph.commands) {
		for (pos = i.begin(); pos != i.end (); ++ pos) {
			cout << pos->first << ": ";
			for (auto j: pos->second)
			{
				cout << graph.ages[j];
				cout << " ";
			}
			
			cout << "\n";
		}		
	}

	cout << "\n\n";
}

void Tasks(Graph graph)
{
	cout << graph.HasCycle() << "\n";
	PrintCommands(graph);
}

void StartTP1(string equipeFile)
{
	Graph graph = GetGraphFromFile(equipeFile);
	Tasks(graph);
}
