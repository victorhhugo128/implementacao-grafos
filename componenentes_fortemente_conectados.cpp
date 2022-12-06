#include "componenentes_fortemente_conectados.hpp"
#include <iostream>

using std::cout;

Cfc::Cfc(Grafo &grafo){
    BuscaEmProfundidade *busca_grafo = new BuscaEmProfundidade(grafo);
    busca_grafo->buscaEmProfundidade('A'); // busca sempre começa do primeiro vértice
    this->t_grafo = busca_grafo->retornaTempoTermino();
    this->grafo_transposto = grafo.grafoTransposto();
    delete busca_grafo;
    this->componentes_fortemente_conectados = {};

    int n = this->grafo_transposto->retornarNVertices();
    this->visitado = new bool[n];
    for(int visita = 0; visita < n; visita++){
        this->visitado[visita] = false;
    }
}

Cfc::~Cfc(){
    delete this->grafo_transposto;
    delete t_grafo;
}

vector<vector<char>> Cfc::cfc(){
    vector<char> temp = {};
    int n = this->grafo_transposto->retornarNVertices(), max_t = -2;

    for(int termino = 0; termino < n; termino++){
        if(t_grafo[termino] > t_grafo[max_t] && !visitado[termino]){
            //cout << t_grafo[termino];
            max_t = termino;
        }
    }
 
    while(max_t != -1){
        this->visitaDfs(max_t + 65, temp);

        this->componentes_fortemente_conectados.push_back(temp);
        /* for(int i = 0; i < temp.size(); i++){
            cout << visitado[i] << "--";
        }
        cout <<"\n"; */
        temp = {};

        max_t = -1;
        for(int termino = 0; termino < n; termino++){
        if(t_grafo[termino] > t_grafo[max_t] && !visitado[termino]){
            //cout << t_grafo[termino];
            max_t = termino;
        }
    }
    }

    return this->componentes_fortemente_conectados;
}

void Cfc::visitaDfs(const char &u, vector<char> &arvore){
    int indice_u = u - 65, indice_v;

    this->visitado[indice_u] = true;
    arvore.push_back(u);

    if(!this->grafo_transposto->listaAdjVazia(u)){ // verifica se o vértice tem adjacências
        Aresta *aresta = this->grafo_transposto->primeiroListaAdj(u); // retorna primeira aresta do vértice
        while(aresta != NULL){
            char v = aresta->v2;
            indice_v = v - 65; // calcula índice
            if(this->visitado[indice_v]){
                aresta = this->grafo_transposto->proxAdj(u);
                continue;
            }
            this->visitaDfs(v, arvore); // chama o método recursivamente para vértice adjancente
            aresta = this->grafo_transposto->proxAdj(u);
        }
    }
}

void Cfc::mostrarArvores(){
    if(componentes_fortemente_conectados.empty()){
        cout << "A operação ainda não foi efetuada.\n\n";
        return;
    }

    cout << "Árvores de vértices fortemente conectados:\n";

    for(int arvore = 0; arvore < componentes_fortemente_conectados.size(); arvore++){
        cout << componentes_fortemente_conectados[arvore][0];
        if(componentes_fortemente_conectados[arvore].size() == 1){
            cout << "\n";
            continue;  
        }
        for(int vertice = 1; vertice < componentes_fortemente_conectados[arvore].size(); vertice++){
            cout << " -- " << componentes_fortemente_conectados[arvore][vertice];
        }
        cout << "\n";
    }
}