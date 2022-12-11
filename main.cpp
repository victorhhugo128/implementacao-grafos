#include<iostream>
#include<cstdlib>
#include<array>
#include "grafo.cpp"
#include "lista_adjacencia.cpp"
#include "busca_em_profundidade.cpp"
#include "componenentes_fortemente_conectados.cpp"
#include "busca_em_largura.cpp"
#include "prim.cpp"
#include "heap_min_vertices.cpp"
#include "dijkstra.cpp"

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

    /* Grafo *grafo_exemplo_slide = new Grafo(10, true);

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

    Grafo *transposto = grafo_exemplo_slide->grafoTransposto();

    grafo_exemplo_slide->mostrarMatriz();

    transposto->mostrarMatriz(); */


    /* Grafo *nao_direcionado_teste = new Grafo(4, false);

    nao_direcionado_teste->inserirAresta('A', 'C');
    nao_direcionado_teste->inserirAresta('C', 'B');
    nao_direcionado_teste->inserirAresta('B', 'A');
    nao_direcionado_teste->inserirAresta('C', 'D');

    nao_direcionado_teste->mostrarMatriz();

    BuscaEmProfundidade *busca_nao_direcionado = new BuscaEmProfundidade(*nao_direcionado_teste);

    busca_nao_direcionado->buscaEmProfundidade('A');
    busca_nao_direcionado->mostrarResultados();
    busca_nao_direcionado->mostraClassificacaoAresta();
    busca_nao_direcionado->grafoCiclico();
    busca_nao_direcionado->mostraOrdenacaoTopologica();

    nao_direcionado_teste->mostrarMatriz(); */

    /* Grafo *grafo_conectado = new Grafo(7, true);

    grafo_conectado->inserirAresta('A', 'B');
    grafo_conectado->inserirAresta('B', 'C');
    grafo_conectado->inserirAresta('C', 'A');
    grafo_conectado->inserirAresta('C', 'E');
    grafo_conectado->inserirAresta('E', 'D');
    grafo_conectado->inserirAresta('D', 'G');
    grafo_conectado->inserirAresta('G', 'F');
    grafo_conectado->inserirAresta('F', 'D'); */

    /* Grafo *grafo_conectado = new Grafo(8, true);

    grafo_conectado->inserirAresta('A', 'B');
    grafo_conectado->inserirAresta('B', 'C');
    grafo_conectado->inserirAresta('B', 'F');
    grafo_conectado->inserirAresta('B', 'E');
    grafo_conectado->inserirAresta('C', 'G');
    grafo_conectado->inserirAresta('C', 'D');
    grafo_conectado->inserirAresta('D', 'C');
    grafo_conectado->inserirAresta('D', 'H');
    grafo_conectado->inserirAresta('E', 'A');
    grafo_conectado->inserirAresta('E', 'F');
    grafo_conectado->inserirAresta('F', 'G');
    grafo_conectado->inserirAresta('G', 'H');
    grafo_conectado->inserirAresta('G', 'F');
    grafo_conectado->inserirAresta('H', 'H');
    grafo_conectado->mostrarMatriz(); */

    /* Grafo *grafo_conectado = new Grafo(8, true);

    grafo_conectado->inserirAresta('A', 'B');
    grafo_conectado->inserirAresta('B', 'C');
    grafo_conectado->inserirAresta('B', 'E');
    grafo_conectado->inserirAresta('B', 'F');
    grafo_conectado->inserirAresta('C', 'D');
    grafo_conectado->inserirAresta('C', 'G');
    grafo_conectado->inserirAresta('D', 'C');
    grafo_conectado->inserirAresta('D', 'H');
    grafo_conectado->inserirAresta('E', 'A');
    grafo_conectado->inserirAresta('F', 'G');
    grafo_conectado->inserirAresta('G', 'F');
    grafo_conectado->inserirAresta('G', 'H');
    grafo_conectado->inserirAresta('H', 'H');

    BuscaEmProfundidade *busca = new BuscaEmProfundidade(*grafo_conectado);

    busca->buscaEmProfundidade('A');
    busca->mostrarResultados();
    Grafo *transposto = grafo_conectado->grafoTransposto();

    transposto->mostrarMatriz();

    Cfc *componentes = new Cfc(*grafo_conectado);

    componentes->cfc();
    componentes->mostrarArvores();

    BuscaEmLargura *busca_largura = new BuscaEmLargura(*grafo_conectado);

    busca_largura->buscaEmLargura('A');

    busca_largura->mostraTempoDescoberta(); */

    /* Grafo *prim_teste = new Grafo(6, false);

    prim_teste->inserirAresta('A', 'B', 6);
    prim_teste->inserirAresta('A', 'C', 1);
    prim_teste->inserirAresta('A', 'D', 5);
    prim_teste->inserirAresta('B', 'C', 2);
    prim_teste->inserirAresta('B', 'E', 5);
    prim_teste->inserirAresta('C', 'D', 2);
    prim_teste->inserirAresta('C', 'E', 6);
    prim_teste->inserirAresta('C', 'F', 4);
    prim_teste->inserirAresta('D', 'F', 4);
    prim_teste->inserirAresta('E', 'F', 3);

    prim_teste->mostrarMatriz();

    Prim *prim = new Prim(*prim_teste);

    prim->algPrim('A');
    prim->mostraResultados(); */

    Grafo *dijkstra_teste = new Grafo(9, false);

    dijkstra_teste->inserirAresta('A', 'B', 4);
    dijkstra_teste->inserirAresta('A', 'H', 8);
    dijkstra_teste->inserirAresta('B', 'C', 8);
    dijkstra_teste->inserirAresta('B', 'H', 11);
    dijkstra_teste->inserirAresta('C', 'D', 7);
    dijkstra_teste->inserirAresta('C', 'I', 2);
    dijkstra_teste->inserirAresta('C', 'F', 4);
    dijkstra_teste->inserirAresta('D', 'E', 9);
    dijkstra_teste->inserirAresta('D', 'F', 14);
    dijkstra_teste->inserirAresta('H', 'G', 1);
    dijkstra_teste->inserirAresta('H', 'I', 7);
    dijkstra_teste->inserirAresta('G', 'I', 6);
    dijkstra_teste->inserirAresta('G', 'F', 2);
    dijkstra_teste->inserirAresta('F', 'E', 10);

    Dijkstra *dijkstra = new Dijkstra(*dijkstra_teste);

    dijkstra->algDijkstra('A');
    dijkstra->mostraResultados();

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