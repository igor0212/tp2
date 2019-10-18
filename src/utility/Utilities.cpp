#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>

using namespace std;

map<int, int> isle;

void Dynamic(string *fileOut){
	*fileOut += "Dynamic\n";
}

void Greedy(string *fileOut){
	*fileOut += "Greedy\n";
}

void Tasks()
{
	string fileOut = "";

	Dynamic(&fileOut);
	Greedy(&fileOut);
	
	cout << fileOut;	
}

void GetDataFromFile(string islandFile)
{	
	string line;	
	ifstream inFile;
	int N, M, counter=1;	
	list<map<int, int>> punctuations;
	
	inFile.open("datasets/" + islandFile);	

	if (!inFile) {
        cout << "Não foi possível abrir o arquivo";
        return;
    }

	//Percorrer todo o arquivo
	while (getline(inFile, line))
	{	
		istringstream s(line);		
		if (counter == 1)
		{  
			//Armazenando primeira linha: numero de pessoas no time, numero de relações
			// diretas entre os membros e numero de instrucoes e criando o grafo
    		if (!(s >> N >> M)) { break; }	
				
		} else if (counter >= 2 && counter < (2 + M))
		{	
			//Criar dicionario (de/para) com as idades das pessoas
			int cost, punctuation;
			if (!(s >> cost >> punctuation)) { break; }			

			isle[cost]	= punctuation;
			punctuations.push_back(isle);			
		}		

		counter++;
	}	

	Tasks();

	inFile.close();			
}