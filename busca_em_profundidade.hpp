#ifndef BUSCAPROFUNDIDADE_H
#define BUSCAPROFUNDIDADE_H
#include "grafo.hpp"

#define BRANCO 0
#define CINZA 1
#define PRETO 2

class BuscaEmProfundidade
{
public:
    BuscaEmProfundidade(Grafo &);
    ~BuscaEmProfundidade();

    void buscaEmProfundidade(const char &); // método para busca em profundidade a partir de um vértice
    void mostrarResultados() const; // imprime cada vértice com o resultado da busca em profundidade anterior
private:
    Grafo *grafo;
    int *d, *t;
    char *antecessor;

    int visitaDfs(const char &, int, int[]); // navega recursuvamente por todos os vértices adjacentes
};


#endif // BUSCAPROFUNDIDADE_H