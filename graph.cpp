#include "graph.hpp"
#include "word_prox.hpp"
#include "fila.hpp"
#include <fstream>

adjNode::adjNode() : prox(nullptr) {}

graphNode::graphNode() : ini(nullptr), nVizinhos(0) {}

int graphNode::at(int i) {

	if(i == 0)
		return ini->pos;

	adjNode* aux = ini;
	int j = 0;
	while(j < i && aux != nullptr) {
		if (j == i)
			return aux->pos;
		aux = aux->prox; 
		j++;
	}

	if (j == i && aux != nullptr)
		return aux->pos;

	return -1;

}

int graphNode::size() {
	return nVizinhos;
}

void graphNode::insereVizinho(int k) {

	adjNode* novo = new adjNode;
	novo->prox = nullptr;
	novo->pos = k;
	nVizinhos++;

	if (ini == nullptr) {
		ini = novo;
		fim = novo;
		return;
	}

	adjNode* aux = ini;
	while (aux->prox != nullptr)
		aux = aux->prox;

	aux->prox = novo;
}

Grafo::Grafo(int k) {

	nodes = new graphNode[1];
	n = 0;
	tam = 1;
	fstream file;
	string palavra, nome_arquivo;
	cout << "Digite o nome do arquivo : ";
	cin >> nome_arquivo;
	cout << endl;
	file.open(nome_arquivo);
	while (file >> palavra) {
		if (palavra.size() >= (unsigned int)k) {
			if (n == tam)
				resize();
			this->insere(palavra);
		}
	}
	file.close();
}


Grafo::~Grafo() {
	adjNode* p, *w;
	for (int i = 0; i < this->n; i++) {
		p = nodes[i].ini;
		while(p != nullptr) {
			w = p->prox;
			delete p;
			p = w;
		}
	}
	delete [] nodes;
}

void Grafo::resize() {

	tam = 2*n;
	graphNode * novo = new graphNode[tam];

	for (int i = 0; i < this->n; i++) 
		novo[i] = nodes[i];

	for (int j = n; j < 2*n; j++) {
		novo[j].ini = nullptr;
	}

	delete [] nodes;

	nodes = novo;
}

int Grafo::find(string palavra) {
	for (int i = 0; i < this->n; i++)
		if (nodes[i].palavra == palavra)
			return i;
	return -1;
}

int Grafo::insere(string palavra) {

	if(find(palavra) != -1)
		return -1;

	int arestas = 0;
	nodes[n].palavra = palavra;

	for (int i = 0; i < this->n; i++) {

		if (wordProximity(nodes[i].palavra, palavra)){
			nodes[n].insereVizinho(i);
			nodes[n].nVizinhos++;
			nodes[i].insereVizinho(n);
			nodes[i].nVizinhos++;
			arestas++;
		}
	}

	n++;
	return arestas;
}

int Grafo::vertices() {
	return this->n;
}

int Grafo::arestas() {

	bool *visited = new bool[this->n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	Fila q;
	int s, j, arestas = 0;

	// começa o bfs

	q.insere(0);
	visited[0] = true;

	while(!q.vazia()) {

		s = q.pop();

		for (int i = 0; i < nodes[s].size(); i++) {

			j = nodes[s].at(i);
			if (j != -1) {
				arestas++;
				if (!visited[j]) {
					
					visited[j] = true;
					q.insere(j);
				}
			}
		}
	}

	delete [] visited;

	return arestas/2;

}

int Grafo::componentes() {

	bool *visited = new bool[this->n];
	int i, comp = 0;

	for (i = 0; i < this->n; i++)
		visited[i] = false;

	for (i = 0; i < this->n; i++) {
		if (!visited[i]) {
			dfsR(i, visited);
			comp++;
		}
	}

	delete [] visited;
	return comp;
}

bool Grafo::conexo() {

	if (this->componentes() > 1)
		return false;
	return true;
}

int Grafo::tamComp(string palavra) {

	int i = this->find(palavra);
	if (i == -1)
		return i;

	bool *visited = new bool[this->n];
	Fila q;
	int j, s, tamanho = 1;

	for (j = 0; j < this->n; j++)
		visited[j] = false;

	q.insere(i);
	visited[i] = true;

	while (!q.vazia()) {

		s = q.pop();

		for (int i = 0; i < nodes[s].size(); i++) {	

			j = nodes[s].at(i);
			if (j != -1) {
				if (!visited[j]) {
					tamanho++;
					visited[j] = true;
					q.insere(j);
				}
			}
		}
	}

	delete [] visited;

	return tamanho;

}

int Grafo::dist(string a, string b) {

	int source = this->find(a);
	int dest = this->find(b);

	if (source == -1 || dest == -1)
		return -1;

	int *pred = new int[this->n];
	Fila q;
	int j, s, dist=0;


	for (int i = 0; i < this->n; i++)
		pred[i] = -1;

	pred[source] = source;

	q.insere(source);

	while(!q.vazia()) {

		s = q.pop();

		if (s == dest)
			break;

		for (int i = 0; i < nodes[s].size(); i++) {

			j = nodes[s].at(i);

			if(j != -1) {
				if (pred[j] == -1) {
					pred[j] = s;
					q.insere(j);
				}
			}

		}
	}


	if (pred[dest] == -1){
		delete [] pred;
		return -1;
	}

	int k = dest;

	while (pred[k] != k) {
		k = pred[k];
		dist++;
	}

	delete [] pred;

	return dist;

}

// bool Grafo::emCiclo(string a) {

// }

void Grafo::dfsR(int i, bool *visited) {

	visited[i] = true;
	for (int j = 0; j < nodes[i].size(); j++) {
		int w = nodes[i].at(j);
		if(w >= 0 && !visited[w])
			dfsR(w, visited);
	}
}

void Grafo::show() {
	
	adjNode* aux;
	for (int i = 0; i < this->n; i++){
		cout << "node " << i << " " + nodes[i].palavra + " -> ";
		cout << "vizinhos : ";
		aux = nodes[i].ini;
		while (aux != nullptr) {
			cout << nodes[aux->pos].palavra + " ";
			aux = aux->prox;
		}
		cout << endl;

	}
	cout << endl;
}
