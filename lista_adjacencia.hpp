#ifndef LISTA_ADJACENCIA_H
#define LISTA_ADJACENCIA_H


class ListaAdjacencia
{   
public:
    ListaAdjacencia(char);
    ~ListaAdjacencia();

    void adicionarAdjacencia(char, int = 1);
    void mostrarLista();
    void retirarAdjacencia(char);

private:
    typedef struct Celula1{
        char chave;
        int peso;
        struct Celula1 *prox_celula;
    }Celula;

    Celula* lista_adjacencia;
    char chave;
};

#endif // LISTA_ADJACENCIA_H