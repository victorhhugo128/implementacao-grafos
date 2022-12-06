#include<iostream>
#include<cstdlib>
#include<array>
#include "grafo.cpp"
#include "lista_adjacencia.cpp"
#include "busca_em_profundidade.cpp"

using std::cout;
using std::end;
using std::begin;

int main(){
    /* char teste = 65;
    Grafo *grafo_teste;
    grafo_teste = new Grafo(3, true);
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

    BuscaEmProfundidade busca_teste(*grafo_teste);

    busca_teste.buscaEmProfundidade('A');

    busca_teste.mostrarResultados();

    cout << grafo_teste->retornarNArestas(); */

    /* Grafo *grafo_exemplo_0 = new Grafo(6, true);

    grafo_exemplo_0->inserirAresta('A', 'B');
    grafo_exemplo_0->inserirAresta('A', 'E');
    grafo_exemplo_0->inserirAresta('B', 'C');
    grafo_exemplo_0->inserirAresta('B', 'E');
    grafo_exemplo_0->inserirAresta('C', 'D');
    grafo_exemplo_0->inserirAresta('D', 'B');
    grafo_exemplo_0->inserirAresta('E', 'D');
    grafo_exemplo_0->inserirAresta('F', 'A');
    grafo_exemplo_0->inserirAresta('F', 'E');

    grafo_exemplo_0->mostrarMatriz();

    BuscaEmProfundidade *busca_exemplo_0 = new BuscaEmProfundidade(*grafo_exemplo_0);

    busca_exemplo_0->buscaEmProfundidade('A');
    busca_exemplo_0->mostrarResultados();

    busca_exemplo_0->mostraClassificacaoAresta();
    busca_exemplo_0->mostraOrdenacaoTopologica(); */

    Grafo *grafo_exemplo_slide = new Grafo(10, true);

    grafo_exemplo_slide->mostrarMatriz();

    grafo_exemplo_slide->inserirAresta('A', 'B');
    grafo_exemplo_slide->inserirAresta('A', 'C');
    grafo_exemplo_slide->inserirAresta('A', 'D');
    grafo_exemplo_slide->inserirAresta('A', 'F');
    grafo_exemplo_slide->inserirAresta('B', 'C');
    grafo_exemplo_slide->inserirAresta('C', 'D');
    grafo_exemplo_slide->inserirAresta('C', 'E');
    grafo_exemplo_slide->inserirAresta('E', 'G');
    grafo_exemplo_slide->inserirAresta('F', 'E');
    grafo_exemplo_slide->inserirAresta('F', 'G');
    grafo_exemplo_slide->inserirAresta('G', 'H');
    grafo_exemplo_slide->inserirAresta('G', 'I');
    grafo_exemplo_slide->inserirAresta('H', 'I');
    grafo_exemplo_slide->inserirAresta('J', 'G');

    grafo_exemplo_slide->mostrarMatriz();

    BuscaEmProfundidade *busca_slide = new BuscaEmProfundidade(*grafo_exemplo_slide);

    busca_slide->buscaEmProfundidade('A');
    busca_slide->mostrarResultados();
    busca_slide->mostraClassificacaoAresta();
    busca_slide->grafoCiclico();
    busca_slide->mostraOrdenacaoTopologica();


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