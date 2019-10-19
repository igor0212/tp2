#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h> 
#include <string.h> 

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, sizeGreedy = 0, sizeDynamic = -1;
int memo[2020][2020];
vector<int> punctuations, costs;

int max(int a, int b) { return (a > b)? a : b; }  

int Greedy(int capacity, vector<int> c, vector<int> p, int n)  
{
	// Armazenar o valor máximo do valor para realiar a viagem 
	int amount[202020];
	memset(amount, 0, sizeof (amount));

    for (int i=0; i<=capacity; i++) 
      for (int j=0; j<n; j++)
         if (c[j] <= i)
            amount[i] = max(amount[i], amount[i - c[j]] + p[j]);  

    return amount[capacity]; 
}

int Dynamic(int index, int capacity) 
{
	// Capacidade não pode ser negativa
	if(capacity < 0) return -INF;	
 	
	// Não consigo escolher mais
	if(index == M) return 0;

	// Caso valor já foi calculado, não é necessário calcular novamente. Basta pegar da matriz de memorização
	int& amount = memo[index][capacity];
	if(amount != -1) return amount;	
	
	// Recursividade que escolhe o caminho máximo (escolhe ou não a ilha)
	amount = max(Dynamic(index + 1, capacity - costs[index]) + punctuations[index], Dynamic(index + 1, capacity));

	if (!amount) sizeDynamic++;

	return amount;
}

void Tasks()
{
	//Greedy
	int greedy = Greedy(N, costs, punctuations, M);
	cout << greedy << " " << sizeGreedy << "\n";

	//Dynamic
	memset(memo, -1, sizeof (memo));
	int dynamic = Dynamic(0, N);
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

	// Percorrer todo o arquivo
	while (getline(inFile, line))
	{	
		istringstream s(line);		
		if (counter == 1)
		{  
			// Armazenando primeira linha: custo maximo em reais e quantidade de ilhas pontuadas
    		if (!(s >> N >> M)) { break; }	
				
		} else if (counter >= 2 && counter < (2 + M))
		{	
			// Criar vetores para o custo de cada ilha e sua pontuacao
			int cost, punctuation;
			if (!(s >> cost >> punctuation)) { break; }			

			punctuations.push_back(punctuation);
			costs.push_back(cost);						
		}		

		counter++;
	}	

	Tasks();

	inFile.close();			
}