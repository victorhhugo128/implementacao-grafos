#include<iostream>
#include "grafo.hpp"

using std::cout;

Grafo::Grafo(int n_vertices, bool direcionado)
:N_VERTICES(n_vertices), DIRECIONADO(direcionado){
    this->vertices = new char[N_VERTICES]; // aloca array de char para vértices
    for(int letra = 65; letra < 65 + N_VERTICES; letra++){ // itera pelos cógidos da tabela ASCII começando por A (cód. 65)
        this->vertices[letra - 65] = letra;
    }

    this->matriz_adjacencia = new int *[N_VERTICES]; // aloca array de ponteiros para guardar matriz_adjacencia
    for(int linha = 0; linha < N_VERTICES; linha++){
        this->matriz_adjacencia[linha] = new int[N_VERTICES]; // aloca uma array de inteiros para cada linha
        for(int coluna = 0; coluna < N_VERTICES; coluna++){
            this->matriz_adjacencia[linha][coluna] = 0; // atribui todos os valores para 0 
        }
    }

    this->pos = new int[N_VERTICES]; // aloca array de inteiros para servir de navegação pelas arestas de cada vértice
    for(int vertice = 0; vertice < N_VERTICES; vertice++){
        this->pos[vertice] = -1; // atribui todos os valores de navegação para -1
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
    coordenadas[0] = -1, coordenadas[1] = -1;

    for(int vertice = 0; vertice < N_VERTICES; vertice++){ // itera pelos vértices para saber se os vértices existem na matriz
        if(v1 == this->vertices[vertice]){
            coordenadas[0] = vertice;
        }
        if(v2 == this->vertices[vertice]){
            coordenadas[1] = vertice;
        }
    }

    return coordenadas; // retorna par de coordenadas
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
    for(int coluna = 0; coluna < N_VERTICES; coluna++){ // conta grau de saída
        if(this->matriz_adjacencia[linha][coluna] > 0){
            grau_saida++;
        }
    }
    for(linha = 0; linha < N_VERTICES; linha++){
        if(linha + 65 == v){
            continue;
        }
        for(int coluna = 0; coluna < N_VERTICES; coluna++){ // conta grau de entrada
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
    if(v1 == v2 && !DIRECIONADO){ // evita self-loops
        cout << "Grafo não direcionado. Impossível adicionar aresta para si mesmo.\n\n";
        return;
    }

    int* coordenadas = this->retornaCoordenadas(v1, v2);

    if(coordenadasValidas(coordenadas)){ // verifica se as coordenadas para a matriz são válidas
        this->matriz_adjacencia[coordenadas[0]][coordenadas[1]] = peso;
        if(!DIRECIONADO){ // se não o grafo não for direcionado
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

    this->matriz_adjacencia[coordenadas[0]][coordenadas[1]] = 0;

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

    int linha = v - 65; // indice do vértice v na amtriz

    for(int i = 0; i < this->N_VERTICES; i++){ // itera pela matriz
        if(this->matriz_adjacencia[linha][i] > 0){
            adjacente = new Aresta;
            adjacente->v1 = v;
            adjacente->v2 = i + 65;
            adjacente->peso = this->matriz_adjacencia[linha][i];
            adjacencias.push_back(adjacente); // armazena arestas adjacentes no vector
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
    if(DIRECIONADO){ // se não direcionado, retorna grau do vértice
        grau = this->retornaGrauVerticeDirecionado(v);
    }
    else{ //s se direcionado, retorna grau de entrada e saída em uma array
        grau = this->retornaGrauVerticeNDirecionado(v); // [entrada, saída]
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

Grafo *Grafo::grafoTransposto() const{
    Grafo *grafo_transposto = new Grafo(this->N_VERTICES, DIRECIONADO);

    for(int linha = 0; linha < this->N_VERTICES; linha++){
        for(int coluna = 0; coluna < this->N_VERTICES; coluna++){
            grafo_transposto->matriz_adjacencia[coluna][linha] = this->matriz_adjacencia[linha][coluna];
        }
    }

    return grafo_transposto;
}