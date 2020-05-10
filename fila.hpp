#ifndef FILA_H
#define FILA_H

using namespace std;

class nodeFila {

	public :
		int pos;
		nodeFila();
		nodeFila* prox;
};

class Fila {
	private :
		nodeFila* ini;
		nodeFila* fim;

	public:
		Fila();
		~Fila();
		void insere(int k);
		int pop();
		bool vazia();
		void print();
};

#endif