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
    Grafo(int = 5, bool = false); // cria grafo sem arestas
    ~Grafo();
    int* retornaCoordenadas(const char &v1, const char &v2) const; // retorna as coordenadas correspondentes aos vértices dados como entrada
    void inserirAresta(const char &, const char &, int = 1);
    void inserirConjuntoArestas(const Aresta[], int); // insere um conjunto de arestas
    Aresta retiraAresta(const char &, const char &);
    bool existeAresta(const char &, const char &) const; // verifica se a aresta especificada existe
    void mostrarMatriz() const;
private:
    vector<char> vertices; // mapeia o rotulo do vertice ao numero atribuido a ele na matriz adjacencia
    vector<vector<int>> matriz_adjacencia;
    const int N_VERTICES;
    const bool DIRECIONADO;
};

#endif // GRAFO_H