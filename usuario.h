#ifndef USUARIO_H
#define USUARIO_H


// Estrutura auxiliar para posições de usuários
typedef struct posicoes{
    Usuario *inicio;
    Usuario *fim;
}Posicoes;

// Estrutura de usuário
typedef struct usuario {
    char nome[50];
    char apelido[30];
    char senha[30];
    struct usuario *prox;
} Usuario;

// Funções relacionadas ao usuário
int login(Usuario *usuarios, char *apelido, char *senha);
Usuario* criarUsuario(char *nome, char *apelido);
void cadastrarUsuario(Usuario **usuarios, char *nome, char *apelido);
void listarUsuarios(Usuario *usuarios);

#endif
