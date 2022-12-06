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

    void buscaEmProfundidade(const char &);
    void mostrarResultados() const;
private:
    Grafo *grafo;
    int *d, *t;
    char *antecessor;

    int visitaDfs(const char &, int, int[]);
};


#endif // BUSCAPROFUNDIDADE_H