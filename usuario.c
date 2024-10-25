#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

// Função para criar um novo usuário
Usuario* criarUsuario(char *nome, char *apelido, char *senha) {
    // Aloca memória para um novo usuário e armazena o ponteiro em 'novo'
    Usuario *novo = (Usuario*) malloc(sizeof(Usuario));

    // Copia o nome, apelido e senha e joga para o novo
    strcpy(novo->nome, nome);
    strcpy(novo->apelido, apelido);
    strcpy(novo->senha, senha);

    // Inicializa o campo prox
    novo->prox = NULL;

    // Retorna essa "unidade" de usuário
    return novo;
}

// Faz o "Login" retornando 1 se a senha bater com o apelido, 0 caso não ou com algum erro encontrado
int login(Usuario *usuarios, char *apelido, char *senha) {
    // Percorre a lista de usuários
    while (usuarios != NULL) {
        // Compara o apelido do usuário atual
        if (strcmp(usuarios->apelido, apelido) == 0) {
            // Compara a senha do usuário atual
            if (strcmp(usuarios->senha, senha) == 0) {
                return 1; // Login funcionou
            } else {
                return 0; // Senha incorreta
            }
        }
        // Avança para o próximo usuário
        usuarios = usuarios->prox;
    }
    return 0; // Usuário não encontrado
}

// Função para cadastrar um novo usuário
void cadastrarUsuario(Usuario **usuarios, char *nome, char *apelido, char *senha) {
    // Cria uma "unidade" de usuário
    Usuario *novo = criarUsuario(nome, apelido, senha);

    //Coloca na lista de usuários
    novo->prox = *usuarios;
    *usuarios = novo;
    printf("Usuário %s (%s) cadastrado com sucesso!\n", nome, apelido);
}

// Função para listar todos os usuários e seus parceiros
void listarUsuarios(Usuario *usuarios) {
    return;
}
