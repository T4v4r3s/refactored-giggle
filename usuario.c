#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

// Função para inicializar a lista
void inicializarLista(Posicoes *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Função para criar um novo usuário
Usuario* criarUsuario(const char *nome, const char *apelido, const char *senha) {
    Usuario *novo = (Usuario*)malloc(sizeof(Usuario));
    strcpy(novo->nome, nome);
    strcpy(novo->apelido, apelido);
    strcpy(novo->senha, senha);
    novo-> chats = NULL;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Função para inserir um usuário na lista de forma ordenada
void inserirOrdenado(Posicoes *lista, Usuario *novo) {
    if (lista->inicio == NULL) {
        // Lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        Usuario *atual = lista->inicio;
        while (atual != NULL && strcmp(atual->nome, novo->nome) < 0) {
            atual = atual->prox;
        }
        if (atual == lista->inicio) {
            // Inserir no início
            novo->prox = lista->inicio;
            lista->inicio->ant = novo;
            lista->inicio = novo;
        } else if (atual == NULL) {
            // Inserir no fim
            lista->fim->prox = novo;
            novo->ant = lista->fim;
            lista->fim = novo;
        } else {
            // Inserir no meio
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;
        }
    }
}

// Função para exibir a lista
void exibirLista(Posicoes *lista) {
    Usuario *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        atual = atual->prox;
    }
}

// Função para liberar a memória da lista
void liberarLista(Posicoes *lista) {
    Usuario *atual = lista->inicio;
    while (atual != NULL) {
        Usuario *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
}