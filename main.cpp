 
#include <iostream>
#include "Graph.h"
#include "Graph.cpp"

using std::cout;

// Graph Implementation using STL
int main( ){
    Graph grafo( 4, true );

    grafo.insereAresta( 'A', 'B', 2);
    //grafo.existeAresta( 1, 1);

    //grafo.aresta( 0, 1, 4 );
    //grafo.existeAresta( 0, 1);

    return 0;
};
