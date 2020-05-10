#include "fila.hpp"
#include <iostream>
using namespace std;

nodeFila::nodeFila() : prox(nullptr) {};

Fila::Fila() : ini(nullptr), fim(nullptr) {};


Fila::~Fila() {
	nodeFila* p = ini,* aux;
	while (p != nullptr) {
		aux = p->prox;
		delete p;
		p = aux;
	}

}

bool Fila::vazia() {
	return ini == nullptr;
}

void Fila::insere(int k) {

	nodeFila* novo = new nodeFila;
	novo->pos = k;
	if (vazia()) {
		fim = ini = novo;
		return;
	}
	fim->prox = novo;
	fim = novo;
}

int Fila::pop() {

	int k = ini->pos;
	nodeFila* aux = ini->prox;
	delete ini;
	ini = aux;
	if (ini == nullptr)
		fim = nullptr;
	return k;
}

void Fila::print() {
	cout << ini->pos << endl;
	for(nodeFila* aux = ini; aux != fim; aux = aux->prox) {
		cout << aux->pos << endl;
	}
}