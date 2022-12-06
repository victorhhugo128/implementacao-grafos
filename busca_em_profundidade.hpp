#ifndef BUSCAPROFUNDIDADE_H
#define BUSCAPROFUNDIDADE_H
#include "grafo.hpp"

#define BRANCO 0
#define CINZA 1
#define PRETO 2

#define ARVORE 0
#define RETORNO 1
#define AVANCO 2
#define CRUZAMENTO 3

class BuscaEmProfundidade
{
public:
    BuscaEmProfundidade(Grafo &);
    ~BuscaEmProfundidade();

    void buscaEmProfundidade(const char &); // método para busca em profundidade a partir de um vértice
    void mostrarResultados() const; // imprime cada vértice com o resultado da busca em profundidade anterior
    void mostraClassificacaoAresta() const;
    bool grafoCiclico() const;
private:
    Grafo *grafo;
    int *d, *t, **matriz_classifica_aresta, ciclos;
    char *antecessor;

    void classificaAresta(const Aresta &, int[]);
    int visitaDfs(const char &, int, int[]); // navega recursuvamente por todos os vértices adjacentes
};


#endif // BUSCAPROFUNDIDADE_H