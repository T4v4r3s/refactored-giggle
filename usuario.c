#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "parceria.h"

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
    
    // Inicializa a lista de parceiros
    novo->parceiros = inicializarListaParceiros();
    // Inicializa a fila de pedidos
    novo->pedido = inicializarFilaPedidos();

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
        novo->prox = NULL;
        novo->ant = NULL;
    } else {
        Usuario *atual = lista->inicio;
        while (atual != NULL && strcmp(atual->nome, novo->nome) < 0) {
            atual = atual->prox;
        }

        if (atual == lista->inicio) {
            // Inserir no início
            novo->prox = lista->inicio;
            novo->ant = NULL;
            lista->inicio->ant = novo;
            lista->inicio = novo;
        } else if (atual == NULL) {
            // Inserir no fim
            lista->fim->prox = novo;
            novo->ant = lista->fim;
            novo->prox = NULL;
            lista->fim = novo;
        } else {
            // Inserir no meio
            novo->prox = atual;
            novo->ant = atual->ant;
            if (atual->ant != NULL) {
                atual->ant->prox = novo;
            }
            atual->ant = novo;
        }
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

// Função para fazer login de um usuário
int login(Posicoes *lista, const char *apelido, const char *senha) {
    Usuario *atual = lista->inicio; // Começar do início da lista

    while (atual != NULL) {
        // Verificar se o apelido e a senha correspondem
        if (strcmp(atual->apelido, apelido) == 0 && strcmp(atual->senha, senha) == 0) {
            return 1; // Login bem-sucedido
        }
        atual = atual->prox; // Passar para o próximo usuário
    }

    return 0; // Login falhou
}

int criarEInserirUsuario(Posicoes *lista, const char *nome, const char *apelido, const char *senha) {
    Usuario *novo = criarUsuario(nome, apelido, senha); // Cria o usuário
    if(novo == NULL){
        return 0;
    }
    inserirOrdenado(lista, novo); // Insere na lista ordenada
    return 1;

}

// Função para buscar um usuário pelo apelido
Usuario* buscarUsuario(Posicoes *lista, const char *apelido) {
    Usuario *atual = lista->inicio; // Começar do início da lista

    while (atual != NULL) {
        // Verificar se o apelido corresponde
        if (strcmp(atual->apelido, apelido) == 0) {
            return atual; // Retorna o usuário encontrado
        }
        atual = atual->prox; // Passar para o próximo usuário
    }

    return NULL; // Usuário não encontrado
}