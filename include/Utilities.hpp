#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

using namespace std;

int max(int a, int b);

int Greedy(int capacity, vector<int> c, vector<int> p, int n);

int Dynamic(int index, int capacity);

void Tasks();

void GetDataFromFile(string islandFile);

#endif