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
    void mostraOrdenacaoTopologica() const;
    int *retornaTempoTermino() const;
    int visitaDfs(const char &, int, int[]); // navega recursivamente por todos os vértices adjacentes
private:
    Grafo *grafo;
    int *d, *t, **matriz_classifica_aresta, ciclos, ordenacao_indice;
    char *antecessor, *ordenacao_topologica;

    void classificaAresta(const Aresta &, int[]);
};


#endif // BUSCAPROFUNDIDADE_H