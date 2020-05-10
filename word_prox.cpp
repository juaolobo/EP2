#include <iostream>
#include "word_prox.hpp"
using namespace std;


bool minusOne(string palavra1, string palavra2) {

	int count = 0, i = 0, j = 0;
	string maior, menor;	

	if (palavra1.size() > palavra2.size())
		maior = palavra1, menor = palavra2;
	else
		menor = palavra1, maior = palavra2;

	while ((unsigned int)j < menor.size()) {
		if (maior[i] == menor[j]) {
			i++;
			j++;
		}
		else {
			i++;
			count++;
		}
		if (count > 1)
			return 0;
	}

	count += maior.size() - menor.size();
	if (count > 1)
		return 0;

	return 1;

}

bool letterPermut(string palavra1, string palavra2, int op) {

	if (palavra2.size() != palavra1.size())
		return 0;
	
	int count = 0,j = 0;

	while ((unsigned int)j < palavra1.size()) {
		if (palavra1[j] != palavra2[j])
			count++;
		if ((count > 1 && op == SUB) || (count > 2 && op == EXC))
			return 0;
		j++;

	}

	return 1;
}

bool wordProximity(string palavra1, string palavra2) {

	return (letterPermut(palavra1, palavra2, EXC) || letterPermut(palavra1, palavra2, SUB) || minusOne(palavra1, palavra2));
}
