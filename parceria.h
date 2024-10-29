#ifndef PARCERIA_H
#define PARCERIA_H

typedef struct pedidos Pedidos;
typedef struct parceiros parceiros;

typedef struct pedidos{
    
    char remetente[30];
    Pedidos *prox;

}pedidos;

typedef struct indexPedidos{
    
    pedidos *inicio;
    pedidos *fim;
}indexPedidos;



typedef struct parceiros{
    
    parceiros *prox;
    char parceiro[30];

}parceiros;

typedef struct indexParceiros{
    
    parceiros *inicio;
    parceiros *fim;
    
}indexParceiros;


//Função da fila de pedidos
pedidos* criarPedido(const char *remetente);
indexPedidos* inicializarFilaPedidos();
void adicionarPedido(indexPedidos *fila, const char *remetente);
pedidos* removerPedido(indexPedidos *fila);
void liberarFila(indexPedidos *fila);
pedidos* mostrarPrimeiroFila(indexPedidos *fila);

//Funções de Lista de parceiros
indexParceiros* inicializarListaParceiros();
parceiros* criarParceiro(const char *parceiroApelido);
int adicionarParceiro(indexParceiros *lista, const char *nomeParceiro);
parceiros* buscarParceiro(indexParceiros *lista, const char *nomeParceiro);


// Funcoes para dar free

void liberarPedidos(indexPedidos *fila);
void liberarParceiros(indexParceiros *listaParceiro);

#endif