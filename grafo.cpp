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
    for(int linha = 0; linha < N_VERTICES; linha++){
        this->matriz_adjacencia[linha] = new int[N_VERTICES];
        for(int coluna = 0; coluna < N_VERTICES; coluna++){
            this->matriz_adjacencia[linha][coluna] = 0;
        }
    }

    this->pos = new int[N_VERTICES];
    for(int vertice = 0; vertice < N_VERTICES; vertice++){
        this->pos[vertice] = -1;
    }
}

Grafo::~Grafo(){
    delete [] this->vertices;
    for(int linha = 0; linha < N_VERTICES; linha++){
        delete [] this->matriz_adjacencia[linha];
    }
    delete [] this->matriz_adjacencia;
    delete [] this->pos;
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

int* Grafo::retornaGrauVerticeNDirecionado(const char &v) const{
    int grau, linha = v - 65;
    for(int coluna = 0; coluna < N_VERTICES; coluna++){
        if(this->matriz_adjacencia[linha][coluna] > 0){
            grau++;
        }
    }

    return new int(grau);
}

int* Grafo::retornaGrauVerticeDirecionado(const char &v) const{
    int grau_entrada = 0, grau_saida = 0, linha = v - 65;
    for(int coluna = 0; coluna < N_VERTICES; coluna++){
        if(this->matriz_adjacencia[linha][coluna] > 0){
            grau_saida++;
        }
    }
    for(linha = 0; linha < N_VERTICES; linha++){
        if(linha + 65 == v){
            continue;
        }
        for(int coluna = 0; coluna < N_VERTICES; coluna++){
            if(this->matriz_adjacencia[linha][coluna] > 0 && coluna == v - 65){
                grau_entrada++;
            }
        }
    }

    return new int[2]{grau_entrada, grau_saida};
}

/* bool Grafo::coordenadasValidas(int coordenadas[2]) const{
    if(coordenadas[0] >= 0 && coordenadas[1] >= 0){
        return true;
    }
    return false;
} */

void Grafo::inserirAresta(const char &v1, const char &v2, int peso){
    if(v1 == v2 && !DIRECIONADO){
        cout << "Grafo não direcionado. Impossível adicionar aresta para si mesmo.\n\n";
        return;
    }

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

int* Grafo::retornaGrauVertice(const char &v) const{
    int *grau;
    if(DIRECIONADO){
        grau = this->retornaGrauVerticeDirecionado(v);
    }
    else{
        grau = this->retornaGrauVerticeNDirecionado(v);
    }
    return grau;
}

bool Grafo::listaAdjVazia(const char &v) const{
    int linha = v - 65;

    for(int coluna = 0; coluna < N_VERTICES; coluna++){
        if(this->matriz_adjacencia[linha][coluna] > 0){
            return false;
        }
    }

    return true;
}

Aresta* Grafo::primeiroListaAdj(const char &v) const{
    int linha  = v - 65;

    this->pos[linha] = -1;

    return this->proxAdj(v);
}

Aresta* Grafo::proxAdj(const char &v) const{
    int linha = v - 65;

    this->pos[linha]++;

    while(this->pos[linha] < N_VERTICES && this->matriz_adjacencia[linha][this->pos[linha]]== 0){
        this->pos[linha]++;
    }

    if(this->pos[linha] == N_VERTICES){
        return NULL;
    }

    Aresta *prox_aresta = new Aresta;

    prox_aresta->v1 = v;
    prox_aresta->v2 = this->pos[linha] + 65;
    prox_aresta->peso = this->matriz_adjacencia[linha][this->pos[linha]];

    return prox_aresta;
}

bool Grafo::coordenadasValidas(int coordenadas[2]){
    if(coordenadas[0] >= 0 && coordenadas[1] >= 0){
        return true;
    }
    return false;
}