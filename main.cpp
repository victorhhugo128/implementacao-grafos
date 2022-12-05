#include<iostream>
#include<cstdlib>
#include<array>
#include "grafo.cpp"
#include "lista_adjacencia.cpp"

using std::cout;
using std::end;
using std::begin;

int main(){
    char teste = 65;
    Grafo *grafo_teste;
    grafo_teste = new Grafo(5, true);
    vector<Aresta*> adjacencias_teste;

    grafo_teste->mostrarMatriz();
    grafo_teste->inserirAresta('A', 'B');
    grafo_teste->mostrarMatriz();
    grafo_teste->inserirAresta('C', 'C');
    grafo_teste->inserirAresta('B', 'A');
    grafo_teste->mostrarMatriz();

    Aresta *aresta_retirada = NULL;

    cout << grafo_teste->existeAresta('A', 'Q') << "\n";

    Aresta aresta1, aresta2, aresta3, *aresta_ptr = NULL;

    aresta1.v1 = 'B';
    aresta1.v2 = 'C';
    aresta1.peso = 12; 

    aresta2.v1 = 'B';
    aresta2.v2 = 'B';
    aresta2.peso = 4;

    aresta3.v1 = 'A';
    aresta3.v2 = 'A';
    aresta3.peso = 2;

    aresta_ptr = new Aresta[3]{aresta1, aresta2, aresta3};

    grafo_teste->inserirConjuntoArestas(aresta_ptr, 3);

    grafo_teste->mostrarMatriz();

    adjacencias_teste = grafo_teste->obterAdjacencias('B');

    cout << "Adjacências do vértice 'B': \n";
    for(int i = 0; i < adjacencias_teste.size(); i++){
        cout << "Aresta(" << adjacencias_teste[i]->v1 << "--" << adjacencias_teste[i]->v2 << ", " <<
        adjacencias_teste[i]->peso << ")\n";
    }

    int *graus = NULL;

    graus = grafo_teste->retornaGrauVertice('B');

    cout << "\nGrau de entrada do vértice 'B': " << graus[0] << "\nGrau de saída do vértice 'B': " << 
    graus[1] << "\n\n";

    grafo_teste->mostrarMatriz();


   /*  ListaAdjacencia lista('A');

    lista.adicionarAdjacencia('B', 2);
    lista.adicionarAdjacencia('C', 2);
    lista.adicionarAdjacencia('D', 2);
    lista.adicionarAdjacencia('E', 2);
    lista.adicionarAdjacencia('F', 2);
    lista.adicionarAdjacencia('F', 2);
    lista.adicionarAdjacencia('G', 2);

    lista.mostrarLista();

    lista.retirarAdjacencia('G');

    lista.mostrarLista();

    lista.retirarAdjacencia('C');

    lista.mostrarLista();

    lista.retirarAdjacencia('B');

    lista.mostrarLista();

    lista.retirarAdjacencia('B');

    lista.mostrarLista();

    lista.retirarAdjacencia('D');

    lista.mostrarLista();

    lista.retirarAdjacencia('F');

    lista.mostrarLista();

    lista.retirarAdjacencia('E');

    lista.mostrarLista();

    lista.retirarAdjacencia('E');

    lista.mostrarLista(); */
        

    return 0;
}