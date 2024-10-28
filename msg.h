#ifndef MSG_H
#define MSG_H

// Declaração do tipo conteudo antes da definição da estrutura
typedef struct conteudo Conteudo;

// Declaração do tipo conversas antes da definição da estrutura
typedef struct conversas Conversas;

struct conteudo{

    char remetente[30];
    char destinatario[30];
    char mensagem[300];
    Conteudo *prox;
    
};

struct conversas{

    char parceiro[30]; //parceiro com quem você estara tendo a conversa
    Conversas *prox;
    Conteudo *cont;

};


Conversas *criarConversa(char *destinatario);
Conteudo *criarConteudo(char *remetente, char *destinatario, char *mensagem);
void pushConteudo(Conversas *conversa, char *remetente, char *destinatario, char *mensagem);

#endif