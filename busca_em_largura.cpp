#include "busca_em_largura.hpp"
#include<iostream>

using std::cout;

BuscaEmLargura::BuscaEmLargura(Grafo &grafo)
{
    this->grafo = &grafo;
    this->fila;
    int n = this->grafo->retornarNVertices();
    this->d = new int[n];
    this->antecessor = new char[n];
    for(int vertice = 0; vertice < n; vertice++){
        this->d[vertice] = -1;
        this->antecessor[vertice] = 48;
    }
}

BuscaEmLargura::~BuscaEmLargura(){
    delete [] d;
    delete [] antecessor;
}

void BuscaEmLargura::buscaEmLargura(char u){
    int n = this->grafo->retornarNVertices(), *cor = new int[n], indice_u = 65 - u, *distancia = new int(0);
    for(int c = 0; c < n; c++){ // inicializa todos os vértices para branco
        cor[c] = BRANCO;
    }

    VerticeDistancia *v = new VerticeDistancia; // inicializa primeiro vértice
    v->distancia = 0;
    v->vertice = u;


    this->fila.push(v); // coloca vértice na fila

    while(true){
        if(fila.empty()){ // se fila estiver vazia, procura vértice ainda não visitado
            for(int c = 0; c < n; c++){
                if(cor[c] == BRANCO){
                    v = new VerticeDistancia; 
                    v->distancia = 0; // reinicializa distância
                    v->vertice = 65 + c;
                    this->fila.push(v); // atribui vértice a fila
                    break;
                }
            }
        }
        if(fila.empty()) break; // se a fila continuar vazia, a busca em largura acabou
        v = fila.front();
        fila.pop(); // tira vértice da fila
        this->visitaBfs(v, cor); // visita vértice
    }

}

void BuscaEmLargura::visitaBfs(VerticeDistancia *u, int cor[]){
    int indice_u = u->vertice - 65, indice_v;
    char v;
    VerticeDistancia *w = NULL;

    cor[indice_u] = CINZA; // muda cor do vértice atual para cinza
    this->d[indice_u] = u->distancia; // atualiza distância do vértice atual

    Aresta *aresta = this->grafo->primeiroListaAdj(u->vertice);
    while(aresta != NULL){
        v = aresta->v2;
        indice_v = v - 65;
        if(cor[indice_v] == BRANCO){
            w = new VerticeDistancia;
            w->distancia = u->distancia + 1; // atualiza distancia do vértice seguinte baseada na distancia do anterior
            w->vertice = v;
            antecessor[indice_v] = u->vertice; // atualiza antecessor do vértice seguinte
            this->fila.push(w); // coloca vértice na fila
        }
        aresta = this->grafo->proxAdj(u->vertice); // passa para o próximo vértice adjacente
    }
    cor[indice_u] = PRETO; // fecha o vértice atual
    delete u;
}

void BuscaEmLargura::mostraTempoDescoberta() const{
    char v;
    for(int vertice = 0; vertice < this->grafo->retornarNVertices(); vertice++){
        v = vertice + 65;
        cout << "Vértice " << v << ":\nd[" << v << "] = " << this->d[vertice] << 
        "\nAntecessor[" << v << "] = " << this->antecessor[vertice] << "\n\n"; 
    }
}