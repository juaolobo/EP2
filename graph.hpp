#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

class adjNode {
	private:
	public:

		adjNode();
		int pos;
		adjNode* prox;
};


class graphNode {
	private:
	public :
	
		int nVizinhos;
		string palavra;
		adjNode* ini;
		adjNode* fim;

		graphNode();
		int at(int i);
		int size();
		void insereVizinho(int k);
};

class Grafo {
	private:
		graphNode *nodes;
		int n;
		int tam;
		void resize();

	public:
		Grafo(int k);
		~Grafo();
		int find(string palavra);
		void dfsR(int i, bool *marked);
		void bfs();
		int insere(string palavra);
		int vertices();
		int arestas();
		int componentes();
		bool conexo();
		int tamComp(string palavra);
		int dist(string a, string b);
		bool emCiclo(string a);
		bool emCiclo(string a, string b);
		void show();
};

#endif