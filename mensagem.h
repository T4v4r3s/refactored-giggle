#ifndef MENSAGEM_H
#define MENSAGEM_H

// Definição da estrutura de mensagem
typedef struct mensagem {
    char texto[100];
    char remetente[30];
    struct mensagem *prox;
} Mensagem;

// Funções relacionadas a mensagens
Mensagem* criarMensagem(char *texto, char *remetente);
void enviarMensagem(Usuario *usuarios, char *apelidoRemetente, char *apelidoDestinatario, char *texto);
void lerMensagens(Usuario *usuarios, char *apelido);

#endif
