#ifndef MSG_H
#define MSG_H

// Declaração do tipo conteudo antes da definição da estrutura
typedef struct conteudo Conteudo;

// Declaração do tipo conversas antes da definição da estrutura
typedef struct conversas Conversas;

typedef struct conteudo{

    char remetente[30];
    char destinatario[30];
    char mensagem[300];
    Conteudo *prox;
    
}Conteudo;

typedef struct conversas {

    char parceiro[30]; //parceiro com quem você estara tendo a conversa
    Conversas *prox;
    Conteudo *cont;

} Conversas;

#endif