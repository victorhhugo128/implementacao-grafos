#include "busca_em_profundidade.hpp"
#include <iostream>

using std::cout;

BuscaEmProfundidade::BuscaEmProfundidade(Grafo &grafo)
{
    this->grafo = &grafo;
    int n = this->grafo->retornarNVertices();
    this->d = new int[n];
    this->t = new int[n];
    this->antecessor = new char[n];
}

BuscaEmProfundidade::~BuscaEmProfundidade()
{
    delete [] this->d;
    delete [] this->t;
    delete [] this->antecessor;
}

void BuscaEmProfundidade::buscaEmProfundidade(){
    int n_vertices = this->grafo->retornarNVertices(), tempo = 0, *cor = new int[n_vertices];

    for(int vertice = 0; vertice < n_vertices; vertice++){
        cor[vertice] = BRANCO;
        this->antecessor[vertice] = 48;
    }

    for(int vertice = 0; vertice < n_vertices; vertice++){
        if(cor[vertice] == BRANCO){
            tempo = this->visitaDfs(vertice + 65, tempo, cor);
        }
    }
}

int BuscaEmProfundidade::visitaDfs(const char &u, int tempo, int cor[]){
    int indice_u = u - 65, indice_v;

    cor[indice_u] = CINZA;
    this->d[indice_u] = ++tempo;

    if(!this->grafo->listaAdjVazia(u)){
        Aresta *aresta = this->grafo->primeiroListaAdj(u);
        while(aresta != NULL){
            char v = aresta->v2;
            indice_v = v - 65;
            if(cor[indice_v] == BRANCO){
                cout << cor[indice_v] << "\n";
                cout << v << "\n";
                this->antecessor[indice_v] = u;
                tempo = this->visitaDfs(v, tempo, cor);
            }
            aresta = this->grafo->proxAdj(u);
        }
    }

    cor[indice_u] = PRETO;
    this->t[indice_u] = ++tempo;

    return tempo;
}

void BuscaEmProfundidade::mostrarResultados() const{
    char v;
    for(int vertice = 0; vertice < this->grafo->retornarNVertices(); vertice++){
        v = vertice + 65;
        cout << "Vértice " << v << ":\nd[" << v << "] = " << d[vertice] << "\nt[" << 
        v << "] = " << t[vertice] << "\nAntecessor[" << v << "] = " << antecessor[vertice] << "\n\n"; 
    }
}