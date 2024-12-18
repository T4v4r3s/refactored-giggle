#include <stdlib.h>
#include <string.h>
#include "parceria.h"

pedidos* criarPedido(char *remetente) {
    pedidos *novoPedido = (pedidos*)malloc(sizeof(pedidos)); // Alocar memória para o novo pedido

    if (novoPedido == NULL) {
        return NULL;
    }

    strncpy(novoPedido->remetente, remetente, sizeof(novoPedido->remetente) - 1);
    novoPedido->remetente[sizeof(novoPedido->remetente) - 1] = '\0'; // Garantindo terminar string por conta de um bug (remover quando arrumar o bug)
    novoPedido->prox = NULL; // Inicializar o próximo ponteiro como NULL

    return novoPedido;
}

// Função para inicializar a fila
indexPedidos* inicializarFilaPedidos() {
    indexPedidos *fila = (indexPedidos*)malloc(sizeof(indexPedidos));
    if (fila == NULL) {
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}


// Função para adicionar um pedido à fila
void adicionarPedido(indexPedidos *fila, char *remetente) {
    pedidos *novoPedido = criarPedido(remetente);
    if (novoPedido == NULL) {
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

// Função para mostrar o elemento mais antigo da fila de pedidos
pedidos* mostrarPrimeiroFila(indexPedidos *fila) {
    if (fila->inicio == NULL) {
        return NULL; // Retorna NULL se a fila estiver vazia
    }
    return fila->inicio; // Retorna o pedido mais antigo
}

//Funções de Lista de parceiros
indexParceiros* inicializarListaParceiros(){
    indexParceiros *lista = (indexParceiros*)malloc(sizeof(indexParceiros));
    if(lista == NULL){
        return NULL;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

parceiros* criarParceiro(char *parceiroApelido){
    parceiros *novoParceiro = (parceiros*)malloc(sizeof(parceiros));

    strcpy(novoParceiro->parceiro, parceiroApelido);
    novoParceiro->prox = NULL;

    return novoParceiro;
}

int adicionarParceiro(indexParceiros *lista, char *nomeParceiro){
    parceiros *novoParceiro = criarParceiro(nomeParceiro);
    if(novoParceiro == NULL){
        return 0;
    }

    if (lista->fim != NULL){
        lista->fim->prox = novoParceiro;
    }

    if(lista->inicio == NULL){
        lista->inicio = novoParceiro;
    }

    lista->fim = novoParceiro;
    return 1;
}

// Função para buscar um parceiro pelo apelido na lista de parceiros
parceiros* buscarParceiro(indexParceiros *lista, char *nomeParceiro) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }

    parceiros *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->parceiro, nomeParceiro) == 0) {
            return atual; // Retorna o ponteiro para o parceiro encontrado
        }
        atual = atual->prox;
    }
    return NULL; // Retorna NULL se o parceiro não foi encontrado
}




// Funcoes para dar free

void liberarPedidos(indexPedidos *fila) {
    if (fila == NULL) return;
    Pedidos *pedido = fila->inicio;
    while (pedido != NULL) {
        Pedidos *temp = pedido;
        pedido = pedido->prox;
        free(temp);
    }
    free(fila);
}

void liberarParceiros(indexParceiros *listaParceiro) {
    if (listaParceiro == NULL) return;
    
    parceiros *parceiroAtual = listaParceiro->inicio;
    while (parceiroAtual != NULL) {
        parceiros *temp = parceiroAtual;
        parceiroAtual = parceiroAtual->prox;
        free(temp);
    }
    free(listaParceiro);
}