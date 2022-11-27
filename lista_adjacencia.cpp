#include "lista_adjacencia.hpp"

#include<iostream>

using std::cout;

ListaAdjacencia::ListaAdjacencia(char chave){ // primeiro elemento da lista sempre é o vértice que partirá as adjacências
    this->lista_adjacencia = NULL;
    this->chave = chave;
}

ListaAdjacencia::~ListaAdjacencia(){
    Celula *ptr = this->lista_adjacencia, *ptr2 = NULL;

    while(ptr){
        ptr2 = ptr;
        ptr = ptr->prox_celula;
        delete ptr2;
    }


}

void ListaAdjacencia::adicionarAdjacencia(char v, int peso){ // adiciona nova adjacência ao final da lista encadeada
    Celula *ptr = NULL;

    if(!this->lista_adjacencia){ // testa se a lista está vazia
        ptr = new Celula;
        this->lista_adjacencia = ptr;
    }
    else{
        ptr = this->lista_adjacencia;
        while(ptr->prox_celula){ // itera até o final da lista para adicionar
            if(ptr->chave == v || ptr->prox_celula->chave == v){ // verifica se a chave já existe na lista
                cout << "Chave " << v << " já existe na lista, não sera possivel adicionar.\n";
                return;
            }
            ptr = ptr->prox_celula;
        }
        ptr->prox_celula = new Celula;
        ptr = ptr->prox_celula;
    }

    // atribui os devidos valores à nova célula.
    ptr->chave = v;
    ptr->peso = peso;
    ptr->prox_celula = NULL;
}

void ListaAdjacencia::mostrarLista(){ // itera pela lista encadeada e mostra todos os elementos.
    Celula *ptr = NULL;

    cout << "|" << this->chave << "|";

    ptr = this->lista_adjacencia;

    while(ptr){
        cout << " -> |" << ptr->chave << "|" << ptr->peso << "|";
        ptr = ptr->prox_celula;
    }

    cout << "⏚\n";
}

void ListaAdjacencia::retirarAdjacencia(char chave){ // retira determinada célula da lista encadeada
    Celula *ptr = NULL, *ptr2 = NULL, *ptr3 = NULL;

    ptr = this->lista_adjacencia;

    if(!ptr){ // caso em que a lista está vazia
        cout << "Impossivel retirar chave, lista vazia.\n";
        return;
    }

    while(ptr->prox_celula){ // procura a chave na lista encadeada
        if(ptr->chave == chave){
            break;
        }
        ptr2 = ptr;
        ptr = ptr->prox_celula;
    }

    if(!ptr->prox_celula && ptr->chave != chave){ // caso a chave não exista na lista
        cout << "Chave " << chave << " não encontrada na lista.\n";
        return;
    }

    else{
        ptr3 = ptr->prox_celula;

        if(ptr == this->lista_adjacencia){ // caso a célula a ser retirada seja a primeira da lista
            this->lista_adjacencia = ptr3;
        }

        else{
            ptr2->prox_celula = ptr3;
        }

        delete ptr;

    }

    cout << "Célula retirada com sucesso!\n";
}   