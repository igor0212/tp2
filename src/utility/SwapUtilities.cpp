#include <list>
#include <algorithm>
#include "../include/GraphUtilities.hpp"

using namespace std;

bool GetSwap(Graph graph, list<int> items)
{
	if(items.empty())
		return false;	

	int item1 = items.front();
	int item2 = items.back();	

	bool hasConnection = find(graph.adj[item1].begin(), graph.adj[item1].end(), item2) != graph.adj[item1].end();

	if(!hasConnection)
		return false;


	return true;
}