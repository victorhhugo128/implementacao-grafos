#include "prim.hpp"
#include<iostream>

Prim::Prim(Grafo &grafo)
{
    this->grafo = &grafo;
    this->lista_de_prioridade = new HeapMinVertices();
    this->n_vertices = this->grafo->retornarNVertices();
    this->antecessores = new char[this->n_vertices];
    this->custo = new int[this->n_vertices];
    for(int vertice = 0; vertice < this->n_vertices; vertice++){
        this->antecessores[vertice] = 48; // inicializa antecessor para '0'
        this->custo[vertice] = INT_MAX; // inicializa todos os vértices com distancia ∞
    }
}

Prim::~Prim()
{
    delete this->lista_de_prioridade;
    delete [] this->antecessores;
    delete [] this->custo;
}

void Prim::algPrim(const char &u){
    int indice_u = u - 65, indice_v;
    char v;
    VerticeCaminho *prox_vertice = NULL;

    Aresta *aresta = this->grafo->primeiroListaAdj(u); // começa do vértice especificado
    custo[indice_u] = 0; // custo inicial 0

    while(aresta != NULL){
        this->lista_de_prioridade->adicionaElemento(aresta->v1, aresta->v2, aresta->peso); // adiciona primeiros vértices adjacentes á lista de prioridade
        aresta = this->grafo->proxAdj(u); // navega pelos vertices adjacentes
    }

    while(!this->lista_de_prioridade->listaVazia()){ // não para até a lista de prioridade destar vazia
        //this->lista_de_prioridade->imprimeMinHeap();
        prox_vertice = this->lista_de_prioridade->retiraMin(); // retira vértice de menor custo
        this->lista_de_prioridade->retiraVerticeV(prox_vertice->vertice); // retira da lista de prioridade todas aas arestas que tenham como destino o vértice que acabou de ser retirado
        v = prox_vertice->vertice;
        //cout << "\nVértice: " << v  << "\nPeso: " << prox_vertice->distancia << "\n\n";
        indice_v = v - 65;
        if(custo[v - 65] == INT_MAX){ // verifica se o vértice já foi visitado
            this->antecessores[indice_v] = prox_vertice->antecessor;
            this->custo[indice_v] = prox_vertice->distancia + custo[prox_vertice->antecessor - 65];
        }
        aresta = this->grafo->primeiroListaAdj(v);
        while(aresta != NULL){
            if(custo[aresta->v2 - 65] == INT_MAX){ // se vertice de destino ainda não foi adicionado à árvore
                this->lista_de_prioridade->adicionaElemento(aresta->v1, aresta->v2, aresta->peso);
            }
            aresta = this->grafo->proxAdj(v);
        }
    }

}

void Prim::mostraResultados() const{
    char v;
    for(int vertice = 0; vertice < this->n_vertices; vertice++){
        v = vertice + 65;
        cout << "Vértice " << v << ":\nCusto[" << v << "] = " << this->custo[vertice] << 
        "\nAntecessor[" << v << "] = " << this->antecessores[vertice] << "\n\n"; 
    }
}