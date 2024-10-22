#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "pedido.h"

// Função para criar um novo pedido
Pedido* criarPedido(char *apelido) {
    Pedido *novo = (Pedido*) malloc(sizeof(Pedido));
    strcpy(novo->apelido, apelido);
    novo->prox = NULL;
    return novo;
}

// Função para pedir parceria
void pedirParceria(Usuario *usuarios, char *apelidoSolicitante, char *apelidoAlvo) {
    Usuario *solicitante = usuarios;
    Usuario *alvo = usuarios;

    // Encontrar solicitante e alvo
    while (solicitante != NULL && strcmp(solicitante->apelido, apelidoSolicitante) != 0) {
        solicitante = solicitante->prox;
    }
    while (alvo != NULL && strcmp(alvo->apelido, apelidoAlvo) != 0) {
        alvo = alvo->prox;
    }

    if (solicitante == NULL || alvo == NULL) {
        printf("Usuário não encontrado!\n");
        return;
    }

    // Criar um novo pedido
    Pedido *novoPedido = criarPedido(apelidoSolicitante);
    novoPedido->prox = alvo->pedidos;
    alvo->pedidos = novoPedido;

    printf("Pedido de parceria enviado por %s para %s.\n", apelidoSolicitante, apelidoAlvo);
}

// Função para avaliar pedidos de parceria
void avaliarPedidos(Usuario *usuarios, char *apelido) {
    Usuario *user = usuarios;

    // Encontrar o usuário
    while (user != NULL && strcmp(user->apelido, apelido) != 0) {
        user = user->prox;
    }

    if (user == NULL) {
        printf("Usuário não encontrado!\n");
        return;
    }

    Pedido *pedido = user->pedidos;
    while (pedido != NULL) {
        printf("%s deseja ser seu parceiro. Aceitar? (sim/não)\n", pedido->apelido);
        char resposta[4];
        scanf("%s", resposta);

        if (strcmp(resposta, "sim") == 0) {
            // Adicionar parceiro
            Parceiro *novoParceiro = criarParceiro(pedido->apelido);
            novoParceiro->prox = user->parceiros;
            user->parceiros = novoParceiro;
            printf("Agora %s é seu parceiro.\n", pedido->apelido);
        }
        Pedido *temp = pedido;
        pedido = pedido->prox;
        free(temp);  // Remover o pedido após avaliação
    }
    user->pedidos = NULL;
}
