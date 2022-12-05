#include<iostream>
#include "grafo.hpp"

using std::cout;

Grafo::Grafo(int n_vertices, bool direcionado)
:N_VERTICES(n_vertices), DIRECIONADO(direcionado){
    this->vertices = new char[N_VERTICES];
    for(int letra = 65; letra < 65 + N_VERTICES; letra++){
        this->vertices[letra - 65] = letra;
    }
    this->matriz_adjacencia = new int *[N_VERTICES];
    for(int i = 0; i < N_VERTICES; i++){
        this->matriz_adjacencia[i] = new int[N_VERTICES];
        for(int j = 0; j < N_VERTICES; j++){
            this->matriz_adjacencia[i][j] = 0;
        }
    }
}

Grafo::~Grafo(){

}

int* Grafo::retornaCoordenadas(const char &v1, const char &v2) const{
    int* coordenadas = new int[2];
    coordenadas[0] = -1;
    coordenadas[1] = -1;

    for(int vertice = 0; vertice < N_VERTICES; vertice++){
        if(v1 == this->vertices[vertice]){
            coordenadas[0] = vertice;
        }
        if(v2 == this->vertices[vertice]){
            coordenadas[1] = vertice;
        }
    }

    return coordenadas;
}

/* bool Grafo::coordenadasValidas(int coordenadas[2]) const{
    if(coordenadas[0] >= 0 && coordenadas[1] >= 0){
        return true;
    }
    return false;
} */

void Grafo::inserirAresta(const char &v1, const char &v2, int peso){
    int* coordenadas = this->retornaCoordenadas(v1, v2);

    if(coordenadasValidas(coordenadas)){
        this->matriz_adjacencia[coordenadas[0]][coordenadas[1]] = peso;
        if(!DIRECIONADO){
            this->matriz_adjacencia[coordenadas[1]][coordenadas[0]] = peso;
        }
        cout << "Aresta " << v1 << "-" << v2 << " adicionada com sucesso.\n\n";
    }
    else{   
        cout << "O conjunto de vértices não é válido.\n\n";
    }

    delete coordenadas;

    return;
} 

void Grafo::inserirConjuntoArestas(const Aresta arestas[], int n_arestas){
    char v1, v2;
    int peso;
    for(int i = 0; i < n_arestas;i++){
        v1 = arestas[i].v1;
        v2 = arestas[i].v2;
        peso = arestas[i].peso; 
        this->inserirAresta(v1, v2, peso);
    }
}

Aresta* Grafo::retiraAresta(const char &v1, const char &v2){
    int *coordenadas = this->retornaCoordenadas(v1, v2);
    Aresta *aresta_retirada = NULL; 

    if(!coordenadasValidas(coordenadas)){
        cout << "Vértices inválidos.\n";
        return NULL;
    }

    if(this->matriz_adjacencia[coordenadas[0]][coordenadas[1]] == 0){
        cout << "Aresta não existe.\n";
        return NULL;
    }

    aresta_retirada = new Aresta;

    aresta_retirada->v1 = v1;
    aresta_retirada->v2 = v2;
    aresta_retirada->peso = this->matriz_adjacencia[coordenadas[0]][coordenadas[1]];

    return aresta_retirada;
}


bool Grafo::existeAresta(const char &v1, const char &v2) const{
    int* coordenadas = this->retornaCoordenadas(v1, v2);
    if(!coordenadasValidas(coordenadas)){
        cout << "Conjunto de vértices " << v1 << "-" << v2 << " inválido.\n";
        return false;
    }

    if(matriz_adjacencia[coordenadas[0]][coordenadas[1]] > 0){
        return true;
    }

    return false;
}

vector<Aresta*> Grafo::obterAdjacencias(const char &v) const{
    Aresta *adjacente = NULL;
    vector<Aresta*> adjacencias;

    int linha = v - 65;

    for(int i = 0; i < this->N_VERTICES; i++){
        if(this->matriz_adjacencia[linha][i] > 0){
            adjacente = new Aresta;
            adjacente->v1 = v;
            adjacente->v2 = i + 65;
            adjacente->peso = this->matriz_adjacencia[linha][i];
            adjacencias.push_back(adjacente);
            adjacente = NULL;
        }
    }
    return adjacencias;
}

void Grafo::mostrarMatriz() const{
    cout << "\t";
    for(int vertice = 0; vertice < N_VERTICES; vertice++){
        cout << this->vertices[vertice] << "\t";
    }
    cout << "\n";

    for(int linha = 0; linha < N_VERTICES; linha++){
        cout << this->vertices[linha];
        for(int coluna = 0; coluna < N_VERTICES; coluna++){
            cout << "\t" << this->matriz_adjacencia[linha][coluna];
        }
        cout << "\n";
    }
    cout << "\n";
}

int Grafo::retornarNVertices() const{
    return this->N_VERTICES;
}


int Grafo::retornarNArestas() const{
    int n_arestas = 0;

    for(int linha = 0; linha < N_VERTICES; linha++){
        for(int coluna = 0; coluna < N_VERTICES; coluna++){
            if(this->matriz_adjacencia[linha][coluna] > 0){
                n_arestas++;
            }
        }
    }

    return n_arestas;
}