#include <iostream>
#include <stdio.h>
#include "include/tp1.hpp"
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{	
	int resultado;	
	clock_t tInicio, tFim, tDecorrido;	

	tInicio = clock();

	if (argc != 2) {
		cout <<  "Argumento invalido";		
		resultado = 0;
	}
	else {					
		string equipeFile = argv[argc-1];			
		StartTP1(equipeFile);
		resultado = 1;
	}		

	tFim = clock();

	//tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	
	//cout << "\nTempo decorrido: " << tDecorrido << " milisegundos \n";

	return resultado;
}