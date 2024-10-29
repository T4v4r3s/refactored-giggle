#ifndef USUARIO_H
#define USUARIO_H

#include "msg.h"
#include "parceria.h"

// Declaração do tipo Usuario antes da definição da estrutura
typedef struct usuario Usuario;

// Estrutura de usuário com ponteiros para o próximo e anterior
struct usuario {
    char nome[50];
    char apelido[30];
    char senha[30];
    indexConversas *chats;
    indexPedidos *pedido;
    indexParceiros *parceiros;
    Usuario *prox;
    Usuario *ant;
};

// Estrutura da lista com ponteiros para o início e fim
typedef struct posicoes {
    Usuario *inicio;
    Usuario *fim;
} Posicoes;

// Declaração das funções
void inicializarLista(Posicoes *lista);
Usuario* criarUsuario(const char *nome, const char *apelido, const char *senha);
void inserirOrdenado(Posicoes *lista, Usuario *novo);
void exibirLista(Posicoes *lista);
void liberarLista(Posicoes *lista);
int login(Posicoes *lista, const char *apelido, const char *senha);
void exibirListaInversa(Posicoes *lista);
int criarEInserirUsuario(Posicoes *lista, const char *nome, const char *apelido, const char *senha);
Usuario* buscarUsuario(Posicoes *lista, const char *apelido);

#endif