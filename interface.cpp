//k definido como no enunciado será passado como argumento de linha de comando
class Grafo{

    public:

    Grafo(int k){
        /* Inicializa um grafo com parâmetro k */
    }

    int insere(string palavra){
        /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
        retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
    }

    int vertices(){
        /* Retorna o número de vértices do grafo*/
    }

    int arestas(){
        /* Retorna o número de arestas do grafo*/
    }

    int componentes(){
        /* Retorna o número de componentes do grafo */
    }

    bool conexo(){
        /* Retorna se o grafo é ou não conexo */
    }

    int tamComp(string palavra){
        /* Retorna o tamanha da componente conexa onde está a palavra
        ou -1 caso ela não se encontre no grafo */
    }

    int dist(string a, string b){
        /* Retorna a menor distância entre as palavras a e b ou -1
        caso elas estejam desconexas ou não estejam no grafo */
    }

    bool emCiclo(string a){
        /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
        falso caso contrário */
    }

    bool emCiclo(string a, string b){
        /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
        falso caso contrário */
    }

}
