#include <iostream>
#include <list>

using namespace std;

class Graph{
    public:
    int numVertices;// sempre vai ser int
    bool digrafo;
    list<int> *listaAdjacencias;// array de listas de adjacencias

    Graph( int numVertices, bool digrafo ){
        
        if ( numVertices >  0 ){// não aceitar valores negativos
            this->numVertices = numVertices;
            this->digrafo = digrafo;
            listaAdjacencias = new list<int>[ numVertices ];// ( aloca armazenamento ) armazena um local da memoria para os "cabecalhos" no caso; por exemplo: numVertices = 6, ele cria 6 vertices que vao ter as listas
        }
    };

    // grafos não direcionados
    void adicionarArestas( int posicaoX, int posicaoY ){
        listaAdjacencias[ posicaoX ].push_back( posicaoY );
        if ( !digrafo ){// não direcionado 
            listaAdjacencias[ posicaoY ].push_back( posicaoX );
           
        }
    };

    // print lista de adjacencias
    void printListaAdjacencia( ){
        for ( int i = 0; i < this->numVertices; i++ ){
            cout << "V" << i << "->";
            for ( int adjancencias:listaAdjacencias[ i ] ){
                cout << adjancencias << "\t|";
            }
            cout << "\n";
        }
    };

};

int main( ){
    Graph grafo( 5, true );// ele é um digrafo ( grafo direcionado )?
    grafo.adicionarArestas( 0, 3);
    grafo.printListaAdjacencia( );
    return 0;
}
