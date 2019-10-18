#ifndef TP2_H
#define TP2_H

#include "../include/GraphUtilities.hpp"
#include <string>

using namespace std;

void Tasks(Graph graph);
void StartTP2(string equipeFile);
void Swap(Graph graph, list<int> items, string *fileOut);
void Commander(Graph graph, list<int> items, string *fileOut);
void Meeting(Graph graph, string *fileOut);

#endif