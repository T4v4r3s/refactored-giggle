#ifndef USUARIO_H
#define USUARIO_H

#include "pedido.h"
#include "mensagem.h"

// Definição de estrutura de parceiro
typedef struct parceiro {
    char apelido[30];
    struct parceiro *prox;
} Parceiro;

// Definição de estrutura de usuário
typedef struct usuario {
    char nome[50];
    char apelido[30];
    Parceiro *parceiros;
    Pedido *pedidos;
    Mensagem *mensagens;
    struct usuario *prox;
} Usuario;

// Funções relacionadas ao usuário
Usuario* criarUsuario(char *nome, char *apelido);
void cadastrarUsuario(Usuario **usuarios, char *nome, char *apelido);
void listarUsuarios(Usuario *usuarios);
Parceiro* criarParceiro(char *apelido);

#endif
