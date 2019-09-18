#ifndef COMMANDERUTILITIES_H
#define COMMANDERUTILITIES_H

#include <Graph.hpp>

using namespace std;

void OrderUtil(int v, bool visited[], Graph alterGraph, list<int> *all);
int Order(int v, Graph alterGraph);
int GetCommander(Graph graph, list<int> items);

#endif