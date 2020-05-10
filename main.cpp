#include "graph.hpp"
#include "word_prox.hpp"
#include "fila.hpp"
#include <iostream>

int main() {
	int k;
	cout << "Digite o número (k) mínimo de letras : ";
	cin >> k;
	Grafo g(k);
	string a = "altura";
	string b = "west";
	g.show();
	int ar = g.arestas();
	int v = g.vertices();
	int c = g.componentes();
	int t = g.tamComp("altura");
	int t2 = g.tamComp("kanye");
	int nt = g.tamComp("rato");
	int dist = g.dist(a, b);
	cout << "arestas : " << ar << endl;
	cout << "vertices : " << v << endl;
	cout << "componentes : " << c << endl;
	cout << "tamanho componente (altura) : " << t << endl;
	cout << "tamanho componente (kanye) : " << t2 << endl;
	cout << "tamanho componente (rato) : " << nt << endl;
	cout << "distancia tem " + a + " e " + b +  " : " << dist <<  endl;

	return 0;
}