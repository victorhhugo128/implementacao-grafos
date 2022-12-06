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
    this->ordenacao_topologica = new char[n];
    for(int vertice = 0; vertice < n; vertice++){ // inicializa arrays
        this->d[vertice] = -1;
        this->t[vertice] = -1;
        this->antecessor[vertice] = 48; // inicializa com char '0'
        this->ordenacao_topologica[vertice] = 48;
    }
    this->matriz_classifica_aresta = new int *[n];
    for(int linha = 0; linha < n; linha++){
        this->matriz_classifica_aresta[linha] = new int[n];
        for(int coluna = 0; coluna < n; coluna++){
            this->matriz_classifica_aresta[linha][coluna] = -1;
        }
    }
    this->ciclos = 0;
    this->ordenacao_indice = n - 1;
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
            if(this->matriz_classifica_aresta[indice_u][indice_v] == -1){ // evita reclassificação de arestas para grafos não direcionados
                this->classificaAresta(*aresta, cor);
            }
            if(cor[indice_v] == BRANCO){
                this->antecessor[indice_v] = u;
                tempo = this->visitaDfs(v, tempo, cor); // chama o método recursivamente para vértice adjancente
            }
            aresta = this->grafo->proxAdj(u);
        }
    }

    cor[indice_u] = PRETO; // conclui e fecha vértice
    cout << u << ", " << cor[indice_u] << "\n";
    this->t[indice_u] = ++tempo; // incrementa tempo e atruibui tempo de término ao vértice atual
    this->ordenacao_topologica[ordenacao_indice] = u;
    this->ordenacao_indice--; 

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

void BuscaEmProfundidade::classificaAresta(const Aresta &aresta, int cor[]){
    int indice_u = aresta.v1 - 65, indice_v = aresta.v2 - 65;
    bool direcionado = this->grafo->DIRECIONADO;

    if(cor[indice_v] == BRANCO){
        this->matriz_classifica_aresta[indice_u][indice_v] = ARVORE;
        if(!direcionado)
            this->matriz_classifica_aresta[indice_v][indice_u] = ARVORE;
        return;
    }

    else if(cor[indice_v] == CINZA){
        this->matriz_classifica_aresta[indice_u][indice_v] = RETORNO;
        this->ciclos += 1;
        if(!direcionado)
            this->matriz_classifica_aresta[indice_v][indice_u] = RETORNO;
        return;
    }
    
    if(this->d[indice_u] > this->d[indice_v]){
        this->matriz_classifica_aresta[indice_u][indice_v] = CRUZAMENTO;
        if(!direcionado)
            this->matriz_classifica_aresta[indice_v][indice_u] = CRUZAMENTO;
        return;
    }

    this->matriz_classifica_aresta[indice_u][indice_v] = AVANCO;
    if(!direcionado)
        this->matriz_classifica_aresta[indice_v][indice_u] = AVANCO;
}

void BuscaEmProfundidade::mostraClassificacaoAresta() const{
    cout << "\t";
    int n = this->grafo->retornarNVertices();
    for(int vertice = 0; vertice < n; vertice++){
        cout << this->grafo->vertices[vertice] << "\t";
    }
    cout << "\n";

    for(int linha = 0; linha < n; linha++){
        cout << this->grafo->vertices[linha];
        for(int coluna = 0; coluna < n; coluna++){
            cout << "\t";
            if(this->matriz_classifica_aresta[linha][coluna] == -1){
                cout << " ";
                continue;
            }
            cout << this->matriz_classifica_aresta[linha][coluna];
        }
        cout << "\n";
    }
    cout << "\n";
}

bool BuscaEmProfundidade::grafoCiclico() const{
    if(this->ciclos == 0){
        cout << "O grafo não tem ciclos.\n\n";
        return false;
    }

    cout << "O grafo tem " << this->ciclos << " ciclo(s).\n\n";
    return true;
}

void BuscaEmProfundidade::mostraOrdenacaoTopologica() const{
    if(!this->grafo->DIRECIONADO){
        cout << "O grafo é não direcionado. Não há ordenação topológica.\n\n";
        return;
    }
    else if(this->ciclos > 0){
        cout << "O grafo tem ciclos. Não há ordenação topológica.\n\n";
        return;
    }
    cout << "Ordenação topológica:\n";
    cout << "|" << this->ordenacao_topologica[0] << "|";
    for(int vertice = 1; vertice < this->grafo->retornarNVertices(); vertice++){
        cout << " -> |" << this->ordenacao_topologica[vertice] << "|";
    }
    cout << "⏚\n";
}