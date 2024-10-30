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
int pushConteudo(Conversas *conversa, char *mensagem);
indexConversas *inicarConversas();
int adicionarConversas(indexConversas *lista,char *parceiro);
char *popConteudo(Conversas *conversa);
Conversas *buscarConversaPorParceiro(indexConversas *lista,char *parceiro);
Conversas *buscarPrimeiraConversaComConteudo(indexConversas *lista);


// Funcoes para dar free

void liberarConteudo(Conteudo *conteudo);
void liberarConversas(indexConversas *chats);

#endif