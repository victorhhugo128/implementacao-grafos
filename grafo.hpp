#ifndef GRAFO_H
#define GRAFO_H
#include<vector>
#include<map>
#include<array>

using std::vector;
using std::map;
using std::array;

class Grafo
{   
public:
    Grafo(int = 5, bool = false); // cria grafo vazio
    void inserirAresta(const char &, const char &, int = 1);
    void mostrarMatriz();
private:
    vector<char> vertices; // mapeia o rotulo do vertice ao numero atribuido a ele na matriz adjacencia
    vector<vector<int>> matriz_adjacencia;
    const int N_VERTICES;
    const bool DIRECIONADO;
};

#endif // GRAFO_H