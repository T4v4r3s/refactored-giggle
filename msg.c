#include "msg.h"
#include <stdlib.h>
#include <string.h>

Conversas *criarConversa(char *destinatario){

    Conversas *novaConversa = (Conversas *)malloc(sizeof(Conversas));
    if(novaConversa == NULL){ // Tratando erro de alocação
        return NULL;
    }

    strncpy(novaConversa->parceiro, destinatario, 30);
    novaConversa->prox = NULL;
    novaConversa->cont = NULL;


    return novaConversa;
    
}

Conteudo *criarConteudo(char *remetente, char *destinatario, char *mensagem){

    Conteudo *novoConteudo = (Conteudo *)malloc(sizeof(Conteudo));
    if(novoConteudo == NULL){ // Tratando erro de alocação
        return NULL;
    }

    strncpy(novoConteudo->remetente, remetente, 30);
    strncpy(novoConteudo->destinatario, destinatario, 30);
    strncpy(novoConteudo->mensagem, mensagem, 300);
    novoConteudo->prox = NULL;

    return novoConteudo;
}