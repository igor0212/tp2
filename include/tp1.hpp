#ifndef TP1_H
#define TP1_H

#include "../include/GraphUtilities.hpp"
#include <string>

using namespace std;

void Tasks(Graph graph);
void StartTP1(string equipeFile);
void PrintCommands(Graph graph);
void Swap(Graph graph, list<int> items, string *fileOut);
void Commander(Graph graph);
void Meeting(Graph graph);

#endif