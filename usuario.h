#ifndef USUARIO_H
#define USUARIO_H


// Estrutura de usuário com ponteiros para o próximo e anterior
typedef struct usuario {
    char nome[50];
    char apelido[30];
    char senha[30];
    struct usuario *prox;
    struct usuario *ant;
} Usuario;

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

#endif