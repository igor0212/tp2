#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

using namespace std;

int max(int a, int b);

int Greedy(int W, vector<int> wt, vector<int> val, int n);

int Dynamic(int W, vector<int> wt, vector<int> val, int n);

void Tasks();

void GetDataFromFile(string islandFile);

#endif