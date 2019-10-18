#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h> 

using namespace std;

int N, M, sizeGreedy = 0, sizeDynamic = 0;
vector<int> value;
vector<int> weight;

int max(int a, int b) { return (a > b)? a : b; }  

int Greedy(int W, vector<int> wt, vector<int> val, int n)  
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n-1] > W)
		return Greedy(W, wt, val, n-1);
    else
		return max(val[n-1] + Greedy(W-wt[n-1], wt, val, n-1), Greedy(W, wt, val, n-1));			  
}  

int Dynamic(int W, vector<int> wt, vector<int> val, int n) 
{ 
   int i, w;

   int** K = new int*[n+1];
   for (int i = 0; i < n+1; i++)
   		K[i] = new int[W+1];
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
			   K[i][w] = 0;
                
           else if (wt[i-1] <= w)
			   K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                  
           else
			   K[i][w] = K[i-1][w];
       } 
   } 
  
   return K[n][W]; 
} 

void Tasks()
{
	int greedy = Greedy(N, weight, value, M);
	cout << greedy << " " << sizeGreedy << "\n";

	int dynamic = Dynamic(N, weight, value, M);
	cout << dynamic << " " << sizeDynamic << "\n";
}

void GetDataFromFile(string islandFile)
{	
	string line;	
	ifstream inFile;
	int counter=1;		
	
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

			value.push_back(punctuation);
			weight.push_back(cost);						
		}		

		counter++;
	}	

	Tasks();

	inFile.close();			
}