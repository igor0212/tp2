#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h> 
#include <string.h> 
#include <map>
#include <list>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, sizeGreedy = 0, sizeDynamic = -1;
int memo[2020][2020];
vector<int> punctuations, costs;
list<float> benefit;
map<float, vector<int>> punctuationsCosts;

int max(int a, int b) { return (a > b)? a : b; }  

int Greedy(int capacity)  
{
	int points = 0;
	
	//Ordernar vetor pelo custo/beneficio
	benefit.sort();	

	// Iniciar loop com o primeiro item
	list<float>::iterator it = benefit.begin();

	while(capacity > 0)
	{		
		vector<int> costPoint = punctuationsCosts[*it];
		int cost = costPoint[0];
		int point = costPoint[1];

		if(cost <= capacity)
		{
			capacity -= cost;
			points += point;
			sizeGreedy++;
		}
		else
		{
			// Se for o ultimo elemento e nao puser mais subtrair da capacida, encerramos o loop
			if(*it == benefit.back())
				break;

			++it;
		}		
	}    

    return points; 
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
	int greedy = Greedy(N);
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
	int counter = 1;		
	
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

			// Criar custo/beneficio para o algoritmo guloso
			float costBenefit = float(cost)/float(punctuation);
			benefit.push_back(costBenefit);	

			// Criar dicionario para armazenar as informacoes
			vector<int> pointCosts;
			pointCosts.push_back(cost);
			pointCosts.push_back(punctuation);
			punctuationsCosts[costBenefit] = pointCosts;
		}		

		counter++;
	}	

	Tasks();

	inFile.close();			
}