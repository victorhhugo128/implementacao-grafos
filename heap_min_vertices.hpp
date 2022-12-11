#ifndef HEAPMINVERTICES_H
#define HEAPMINVERTICES_H
#include <vector>

using std::vector;

struct VerticeCaminho{
    int distancia;
    char vertice, antecessor;
};

class HeapMinVertices
{
    public:
        HeapMinVertices();
        ~HeapMinVertices();
        void adicionaElemento(char &, char &, int);
        void constroiMinHeap();
        void imprimeMinHeap();
        VerticeCaminho* retiraMin();
        void retiraVerticeV(const char &);
        bool listaVazia() const;
    private:
        vector<VerticeCaminho*> vertices;
        static int pai(int);
        static int esq(int);
        static int dir(int);
        void minHeapify(int indice);
        void buildMinHeap();

};

#endif // HEAPMINVERTICES_M