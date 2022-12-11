#include "heap_min_vertices.hpp"
#include <iostream>
#include <cmath>

using std::ceil;
using std::cout;

HeapMinVertices::HeapMinVertices(){
    this->vertices = {};
}

HeapMinVertices::~HeapMinVertices(){
    for(int vertice = 0; vertice < vertices.size(); vertice++){
        delete this->vertices[vertice];
    }
}

int HeapMinVertices::pai(int indice){
    float temp = indice;
    return ceil(temp / 2 - 1);
}

int HeapMinVertices::esq(int indice){
    return indice * 2 + 1;
}

int HeapMinVertices::dir(int indice){
    return indice * 2  + 2;
}

void HeapMinVertices::adicionaElemento(char &antecessor, char &vertice, int distancia){
    VerticeCaminho *temp = new VerticeCaminho;
    temp->distancia = distancia;
    temp->antecessor = antecessor;
    temp->vertice = vertice;
    this->vertices.push_back(temp);
    this->constroiMinHeap();
}

void HeapMinVertices::minHeapify(int indice){
    int esquerdo = esq(indice), direito = dir(indice), menor;

    if(esquerdo < this->vertices.size() && this->vertices[esquerdo]->distancia < this->vertices[indice]->distancia){
        menor = esquerdo;
    }
    else{
        menor = indice;
    }

    if(direito < this->vertices.size() && this->vertices[direito]->distancia < this->vertices[menor]->distancia){
        menor = direito;
    }

    if(menor != indice){
        VerticeCaminho *temp = this->vertices[indice];
        this->vertices[indice] = this->vertices[menor];
        this->vertices[menor] = temp;
        this->minHeapify(menor);
    }

}

void HeapMinVertices::constroiMinHeap(){
    for(int i = this->vertices.size()/2; i >= 0; i--){
        this->minHeapify(i);
    }
}

void HeapMinVertices::imprimeMinHeap(){
    cout << "(" << this->vertices[0]->antecessor << ", " << this->vertices[0]->vertice << ", " << this->vertices[0]->distancia << ")";
    for(int vertice = 1; vertice < this->vertices.size(); vertice++){
        cout << ", (" << this->vertices[vertice]->antecessor << ", " << this->vertices[vertice]->vertice << ", " << this->vertices[vertice]->distancia << ")";
    }
    cout << "\n\n";
}

VerticeCaminho *HeapMinVertices::retiraMin(){
    if(this->vertices.empty()){
        cout << "Heap vazia.\n\n";
        return NULL;
    }

    VerticeCaminho *temp = this->vertices.front();

    this->vertices.erase(this->vertices.begin());

    this->constroiMinHeap();

    return temp;
}

void HeapMinVertices::retiraVerticeV(const char &u){
    for(int vertice = 0; vertice < this->vertices.size(); vertice++){
        if(u == this->vertices[vertice]->vertice){
            this->vertices.erase(vertices.begin() + vertice);
        }
    }
    this->constroiMinHeap();
}

bool HeapMinVertices::listaVazia() const{
    return this->vertices.empty();
}