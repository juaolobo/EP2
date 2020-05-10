#ifndef WORD_PROX_H
#define WORD_PROX_H

#include <iostream>
using namespace std;	

#define SUB 1 // letterSubstitution
#define EXC 0 // letterExchange

bool minusOne(string palavra1, string palavra2);
bool letterPermut(string palavra1, string palavra2, int op);
bool wordProximity(string palavra1, string palavra2);

#endif