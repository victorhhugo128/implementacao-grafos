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
    for(int vertice = 0; vertice < n; vertice++){ // inicializa arrays
        this->d[vertice] = -1;
        this->t[vertice] = -1;
        this->antecessor[vertice] = 48; // inicializa com char '0'
    }
}

BuscaEmProfundidade::~BuscaEmProfundidade()
{
    delete [] this->d;
    delete [] this->t;
    delete [] this->antecessor;
}

void BuscaEmProfundidade::buscaEmProfundidade(const char &v){
    int n_vertices = this->grafo->retornarNVertices(), tempo = 0, *cor = new int[n_vertices];

    for(int vertice = 0; vertice < n_vertices; vertice++){ // inicializa todos os vértices para cor branco
        cor[vertice] = BRANCO;
    }

    /* for(int vertice = 0; vertice < n_vertices; vertice++){
        if(cor[vertice] == BRANCO){
            tempo = this->visitaDfs(vertice + 65, tempo, cor);
        }
    } */

    int indice = v - 65, vertice = indice; // define índice do vértice

    do{
        if(cor[vertice] == BRANCO){
            tempo = this->visitaDfs(vertice + 65, tempo, cor);
        }
        vertice = (vertice + 1) % n_vertices; // iteração cíclica para cobrir todos os vértices do grafo
    }while(vertice != indice); // itera até que um ciclo pelos vértices sejam completos

}

int BuscaEmProfundidade::visitaDfs(const char &u, int tempo, int cor[]){
    int indice_u = u - 65, indice_v;

    cor[indice_u] = CINZA;
    this->d[indice_u] = ++tempo; // incrementa tempo e atribui a descoberta do vértice atual

    if(!this->grafo->listaAdjVazia(u)){ // verifica se o vértice tem adjacências
        Aresta *aresta = this->grafo->primeiroListaAdj(u); // retorna primeira aresta do vértice
        while(aresta != NULL){
            char v = aresta->v2;
            indice_v = v - 65; // calcula índice
            if(cor[indice_v] == BRANCO){
                this->antecessor[indice_v] = u;
                tempo = this->visitaDfs(v, tempo, cor); // chama o método recursivamente para vértice adjancente
            }
            aresta = this->grafo->proxAdj(u);
        }
    }

    cor[indice_u] = PRETO; // conclui e fecha vértice
    this->t[indice_u] = ++tempo; // incrementa tempo e atruibui tempo de término ao vértice atual

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