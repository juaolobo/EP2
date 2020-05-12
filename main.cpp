#include "graph.hpp"
#include "word_prox.hpp"
#include "fila.hpp"
#include <iostream>

int main(int argc, char **argv) {

	if (argc < 2){
		cout << "faltou o argumento" << endl;
		return 0;
	}

	Grafo g(atoi(argv[1]));
	string a = "altura";
	string b = "west";
	string cc = "gato";
	string cc2 = "altura";
	g.show();
	int ar = g.arestas();
	int v = g.vertices();
	int c = g.componentes();
	int t = g.tamComp("altura");
	int t2 = g.tamComp("kanye");
	int nt = g.tamComp("rato");
	int dist = g.dist(a, b);
	int cicl = g.emCiclo(cc);
	int cicl2 = g.emCiclo(cc, cc2);
	cout << "arestas : " << ar << endl;
	cout << "vertices : " << v << endl;
	cout << "componentes : " << c << endl;
	cout << "tamanho componente (altura) : " << t << endl;
	cout << "tamanho componente (kanye) : " << t2 << endl;
	cout << "tamanho componente (rato) : " << nt << endl;
	cout << "distancia tem " + a + " e " + b +  " : " << dist <<  endl;
	cout << "ciclo ("+ cc + ") : " << cicl << endl;

	cout << "ciclo ("+ cc + " " + cc2 + ") : " << cicl2 << endl;

	return 0;
}