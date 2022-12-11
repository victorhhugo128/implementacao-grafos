#ifndef PRIM_H
#define PRIM_H
#include <climits>
#include "heap_min_vertices.hpp"
#include "grafo.hpp"

class Prim
{
    public:
        Prim(Grafo &);
        ~Prim();

        void algPrim(const char &);
        void mostraResultados() const;
    private:
        Grafo *grafo;
        HeapMinVertices *lista_de_prioridade;
        char *antecessores;
        int *custo;
        int n_vertices;
};

#endif // PRIM_H