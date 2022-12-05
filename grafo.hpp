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

bool coordenadasValidas(int coordenadas[2]){
    if(coordenadas[0] >= 0 && coordenadas[1] >= 0){
        return true;
    }
    return false;
}

class Grafo
{   
public:
    Grafo(int = 5, bool = false); // cria grafo sem arestas (a)
    ~Grafo();
    void inserirAresta(const char &, const char &, int = 1); //(b)
    void inserirConjuntoArestas(const Aresta[], int); // insere um conjunto de arestas (c)
    Aresta* retiraAresta(const char &, const char &); // (d)
    bool existeAresta(const char &, const char &) const; // verifica se a aresta especificada existe (e)
    vector<Aresta*> obterAdjacencias(const char &) const; // obtém todas as adjacencias do vértice escolhido
    void mostrarMatriz() const; // (g)
    int retornarNVertices() const; // (h)
    int retornarNArestas() const; // (h)
    int* retornaGrauVertice(const char &) const;

private:
    int* retornaCoordenadas(const char &v1, const char &v2) const; // retorna as coordenadas correspondentes aos vértices dados como entrada
    int* retornaGrauVerticeNDirecionado(const char &) const; // (i)
    int* retornaGrauVerticeDirecionado(const char &) const; // (j)
    char *vertices; // mapeia o rotulo do vertice ao numero atribuido a ele na matriz adjacencia
    int **matriz_adjacencia;
    const int N_VERTICES;
    const bool DIRECIONADO;
};

#endif // GRAFO_H