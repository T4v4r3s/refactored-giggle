#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"
#include "mensagem.h"
#include "usuario.h"

// Função para criar um novo usuário
Usuario* criarUsuario(char *nome, char *apelido) {
    Usuario *novo = (Usuario*) malloc(sizeof(Usuario));
    strcpy(novo->nome, nome);
    strcpy(novo->apelido, apelido);
    novo->parceiros = NULL;
    novo->pedidos = NULL;
    novo->prox = NULL;
    return novo;
}

// Função para cadastrar um novo usuário
void cadastrarUsuario(Usuario **usuarios, char *nome, char *apelido) {
    Usuario *novo = criarUsuario(nome, apelido);
    novo->prox = *usuarios;
    *usuarios = novo;
    printf("Usuário %s (%s) cadastrado com sucesso!\n", nome, apelido);
}

// Função para listar todos os usuários e seus parceiros
void listarUsuarios(Usuario *usuarios) {
    Usuario *temp = usuarios;
    while (temp != NULL) {
        printf("Usuário: %s (%s)\n", temp->nome, temp->apelido);
        printf("Parceiros:\n");
        Parceiro *p = temp->parceiros;
        while (p != NULL) {
            printf(" - %s\n", p->apelido);
            p = p->prox;
        }
        temp = temp->prox;
    }
}

// Função para criar um parceiro
Parceiro* criarParceiro(char *apelido) {
    Parceiro *novo = (Parceiro*) malloc(sizeof(Parceiro));
    strcpy(novo->apelido, apelido);
    novo->prox = NULL;
    return novo;
}
