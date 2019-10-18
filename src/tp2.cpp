#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <sstream> 
#include "../include/Utilities.hpp"

using namespace std;

void Tasks()
{
	string fileOut = "";
	typedef map <string, list<int>> StringFloatMap;
	StringFloatMap :: iterator pos;		
	
	cout << fileOut;	
}

void StartTP2(string ilhaFile)
{	
	//Criação do grafo, dicionario de idades e lista de dicionarios dos comandos
	GetDataFromFile(ilhaFile);

	//Realizar comandos (Swap, Commander, Meeting)
	Tasks();
}