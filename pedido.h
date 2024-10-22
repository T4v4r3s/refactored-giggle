#ifndef PEDIDO_H
#define PEDIDO_H

// Definição da estrutura de pedido
typedef struct pedido {
    char apelido[30]; // Apelido do solicitante
    struct pedido *prox;
} Pedido;

// Funções relacionadas a pedidos
Pedido* criarPedido(char *apelido);
void pedirParceria(Usuario *usuarios, char *apelidoSolicitante, char *apelidoAlvo);
void avaliarPedidos(Usuario *usuarios, char *apelido);

#endif
