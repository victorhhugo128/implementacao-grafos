#ifndef CFC_h
#define CFC_h
#include "grafo.hpp"
#include "busca_em_profundidade.hpp"
#include<vector>

using std::vector;

class Cfc{
    public:
        Cfc(Grafo &);
        ~Cfc();

        vector<vector<char>> cfc();
        void visitaDfs(const char &, vector<char> &);
        void mostrarArvores();
    private:
        Grafo *grafo_transposto;
        int *t_grafo;
        bool *visitado;
        vector<vector<char>> componentes_fortemente_conectados;
};

#endif // CFC_H