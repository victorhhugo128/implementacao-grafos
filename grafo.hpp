#ifndef GRAFO_H
#define GRAFO_H
#include<vector>
#include<map>
#include<array>

using std::vector;
using std::map;
using std::array;

struct Aresta{
    char v1, v2;
    int peso = 1;
};

/* void atribui_aresta(Aresta &aresta, const char &v1, const char &v2, int peso){
    aresta.v1 = v1;
    aresta.v2 = v2;
    aresta.peso = peso;
} */

/* bool coordenadasValidas(int coordenadas[2]){
    if(coordenadas[0] >= 0 && coordenadas[1] >= 0){
        return true;
    }
    return false;
} */

class Grafo
{   
public:
    friend class BuscaEmProfundidade;

    Grafo(int = 5, bool = false); // cria grafo sem arestas (a)
    ~Grafo();
    void inserirAresta(const char &, const char &, int = 1); //(b)
    void inserirConjuntoArestas(const Aresta[], int); // insere um conjunto de arestas (c)
    Aresta* retiraAresta(const char &, const char &); // exclui aresta da matriz e retorna um struct Aresta (d)
    bool existeAresta(const char &, const char &) const; // verifica se a aresta especificada existe (e)
    vector<Aresta*> obterAdjacencias(const char &) const; // obtém todas as adjacencias do vértice escolhido
    void mostrarMatriz() const; // imprime matriz (g)
    int retornarNVertices() const; // (h)
    int retornarNArestas() const; // (h)
    int* retornaGrauVertice(const char &) const; // retorna grau de um vértice(i-h)
    bool listaAdjVazia(const char &) const; // verifica se o vértice especificado tem adjacências a ele
    Aresta* primeiroListaAdj(const char &) const; // retorna primeira adjacência de vértice especificado
    Aresta* proxAdj(const char &) const; // retorna a próxima aresta a partir da array pos[] atual 
    Grafo* grafoTransposto() const;

private:
    int* retornaCoordenadas(const char &v1, const char &v2) const; // retorna as coordenadas correspondentes aos vértices dados como entrada
    int* retornaGrauVerticeNDirecionado(const char &) const; // (i)
    int* retornaGrauVerticeDirecionado(const char &) const; // (j)
    static bool coordenadasValidas(int[]); // verifica se um par de coordenadas existe na matriz
    char *vertices; // guarda nome de vértices
    int **matriz_adjacencia;
    int *pos; // posição ao se percorrer as arestas de um vértice
    const int N_VERTICES;
    const bool DIRECIONADO;
};

#endif // GRAFO_H