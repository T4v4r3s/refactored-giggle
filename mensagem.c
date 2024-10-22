#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "mensagem.h"

// Função para criar uma nova mensagem
Mensagem* criarMensagem(char *texto, char *remetente) {
    Mensagem *nova = (Mensagem*) malloc(sizeof(Mensagem));
    strcpy(nova->texto, texto);
    strcpy(nova->remetente, remetente);
    nova->prox = NULL;
    return nova;
}

// Função para enviar uma mensagem
void enviarMensagem(Usuario *usuarios, char *apelidoRemetente, char *apelidoDestinatario, char *texto) {
    Usuario *remetente = usuarios;
    Usuario *destinatario = usuarios;

    // Encontrar o remetente e destinatário
    while (remetente != NULL && strcmp(remetente->apelido, apelidoRemetente) != 0) {
        remetente = remetente->prox;
    }
    while (destinatario != NULL && strcmp(destinatario->apelido, apelidoDestinatario) != 0) {
        destinatario = destinatario->prox;
    }

    if (remetente == NULL || destinatario == NULL) {
        printf("Usuário não encontrado!\n");
        return;
    }

    Mensagem *novaMensagem = criarMensagem(texto, apelidoRemetente);
    novaMensagem->prox = destinatario->mensagens;
    destinatario->mensagens = novaMensagem;

    printf("Mensagem enviada com sucesso de %s para %s.\n", apelidoRemetente, apelidoDestinatario);
}

// Função para ler mensagens
void lerMensagens(Usuario *usuarios, char *apelido) {
    Usuario *user = usuarios;

    // Encontrar o usuário
    while (user != NULL && strcmp(user->apelido, apelido) != 0) {
        user = user->prox;
    }

    if (user == NULL) {
        printf("Usuário não encontrado!\n");
        return;
    }

    Mensagem *msg = user->mensagens;
    while (msg != NULL) {
        printf("Mensagem de %s: %s\n", msg->remetente, msg->texto);
        Mensagem *temp = msg;
        msg = msg->prox;
        free(temp);  // Apaga as mensagens após leitura
    }
    user->mensagens = NULL;
}
