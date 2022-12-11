#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <climits>
#include "heap_min_vertices.hpp"
#include "grafo.hpp"

class Dijkstra
{
    public:
        Dijkstra(Grafo &);
        ~Dijkstra();

        void algDijkstra(const char &);
        void mostraResultados() const;
    private:
        Grafo *grafo;
        HeapMinVertices *lista_de_prioridade;
        char *antecessores;
        int *custo;
        int n_vertices;
};

#endif // DIJKSTRA_H