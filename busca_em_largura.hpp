#ifndef BUSCAEMLARGURA_H
#define BUSCAEMLARGURA_H
#include <queue>
#include "grafo.hpp"

using std::queue;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

struct VerticeDistancia{
    int distancia;
    char vertice;
};

class BuscaEmLargura
{
    public:
        BuscaEmLargura(Grafo &);
        ~BuscaEmLargura();

        void buscaEmLargura(char);
        void visitaBfs(VerticeDistancia*,  int[]);
        void mostraTempoDescoberta() const;
    private:
        Grafo *grafo;
        queue<VerticeDistancia*> fila;
        int *d;
        char *antecessor;

};

#endif // BUSCAEMLARGURA_H