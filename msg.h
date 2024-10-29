#ifndef MSG_H
#define MSG_H

// Declaração do tipo conteudo antes da definição da estrutura
typedef struct conteudo Conteudo;

// Declaração do tipo conversas antes da definição da estrutura
typedef struct conversas Conversas;

struct conteudo{

    char mensagem[300];
    Conteudo *prox;
    
};

typedef struct indexConversas{

    Conversas *inicio;
    Conversas *fim;

}indexConversas;

struct conversas{

    char parceiro[30]; //parceiro com quem você estara tendo a conversa
    Conversas *prox;
    Conteudo *cont;

};




Conversas *criarConversa(char *destinatario);
Conteudo *criarConteudo(char *mensagem);
void pushConteudo(Conversas *conversa, char *mensagem);
indexConversas *inicarConversas();
int adicionarConversas(indexConversas *lista,char *parceiro);

#endif