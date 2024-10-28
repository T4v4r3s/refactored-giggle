#ifndef PARCERIA_H
#define PARCERIA_H


typedef struct pedidos{
    
    char remetente[30];
    pedidos *prox;

}pedidos;

typedef struct indexPedidos{
    
    pedidos *inicio;
    pedidos *fim;
}indexPedidos;



typedef struct parceiros{
    
    parceiros *prox;
    char parceiro[30];

}parceiros;

pedidos* criarPedido(const char *remetente);


#endif