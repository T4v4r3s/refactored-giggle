#include <stdlib.h>
#include "parceria.h"

pedidos* criarPedido(const char *remetente) {
    pedidos *novoPedido = (pedidos*)malloc(sizeof(pedidos)); // Alocar memória para o novo pedido

    if (novoPedido == NULL) {
        return NULL;
    }

    strncpy(novoPedido->remetente, remetente, sizeof(novoPedido->remetente) - 1);
    novoPedido->remetente[sizeof(novoPedido->remetente) - 1] = '\0'; // Garantir a terminação da string
    novoPedido->prox = NULL; // Inicializar o próximo ponteiro como NULL

    return novoPedido;
}

// Função para inicializar a fila
indexPedidos* iniciarFila() {
    indexPedidos *fila = (indexPedidos*)malloc(sizeof(indexPedidos));
    if (fila == NULL) {
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}


// Função para adicionar um pedido à fila
void adicionarPedido(indexPedidos *fila, const char *remetente) {
    pedidos *novoPedido = criarPedido(remetente);
    if (novoPedido == NULL) {
        printf("Erro ao alocar memória para o novo pedido.\n");
        return;
    }

    if (fila->fim != NULL) {
        fila->fim->prox = novoPedido; // O próximo do último elemento é o novo pedido
    }
    fila->fim = novoPedido; // Atualiza o fim da fila

    if (fila->inicio == NULL) {
        fila->inicio = novoPedido; // Se a fila estava vazia, o novo pedido é o início
    }
}


// Função para remover um pedido da fila
pedidos* removerPedido(indexPedidos *fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia. Não há pedidos para remover.\n");
        return NULL;
    }

    pedidos *pedidoRemovido = fila->inicio; // Guarda o pedido a ser removido
    fila->inicio = fila->inicio->prox; // Move o início da fila para o próximo pedido

    if (fila->inicio == NULL) {
        fila->fim = NULL; // Se a fila ficou vazia, atualiza o fim também
    }

    return pedidoRemovido; // Retorna o pedido removido
}

// Função para liberar a memória da fila
void liberarFila(indexPedidos *fila) {
    pedidos *atual = fila->inicio;
    while (atual != NULL) {
        pedidos *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}