#include "msg.h"
#include <stdlib.h>
#include <string.h>


indexConversas *inicarConversas(){

    indexConversas *lista = (indexConversas*)malloc(sizeof(indexConversas));

    if(lista == NULL){
        return NULL;
    }

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;

}

int adicionarConversas(indexConversas *lista, char *parceiro){

    Conversas *chat = criarConversa(parceiro);

    if (chat == NULL){
        return 0;
    }

    if(lista->fim != NULL){
        lista->fim->prox = chat;
    }

    if(lista->inicio == NULL){
        lista->inicio = chat;
    }
    
    lista->fim = chat;

    return 1;
}

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

Conteudo *criarConteudo(char *mensagem){

    Conteudo *novoConteudo = (Conteudo *)malloc(sizeof(Conteudo));
    if(novoConteudo == NULL){ // Tratando erro de alocação
        return NULL;
    }

    strncpy(novoConteudo->mensagem, mensagem, 300);
    novoConteudo->prox = NULL;

    return novoConteudo;
}

// Função para adicionar um novo conteúdo ao topo da pilha
void pushConteudo(Conversas *conversa, char *mensagem) {
    Conteudo *novoConteudo = (Conteudo *)malloc(sizeof(Conteudo));
    if (novoConteudo == NULL) { // Tratando erro de alocação
        return;
    }

    strncpy(novoConteudo->mensagem, mensagem, 300);

    // Adiciona o novo conteúdo ao topo da pilha
    novoConteudo->prox = conversa->cont;
    conversa->cont = novoConteudo;
}

// Função para remover o conteúdo do topo da pilha
Conteudo *popConteudo(Conversas *conversa) {
    if (conversa->cont == NULL) {
        return NULL; // Pilha vazia
    }

    Conteudo *topo = conversa->cont;
    conversa->cont = topo->prox;
    topo->prox = NULL;

    return topo;
}




/*
// Mostra as mensagens da conversa sendo a
void mostrarMensagensConversa(Conversas *conversa) {
    // Pilha temporária para inverter a ordem
    Conteudo *pilhaTemporaria = NULL;

    // Retira todos os conteúdos da conversa original e empilha na pilha temporária
    while (conversa->cont != NULL) {
        Conteudo *msg = popConteudo(conversa);
        msg->prox = pilhaTemporaria;
        pilhaTemporaria = msg;
    }

    // Imprime e libera as mensagens da pilha temporária, restaurando-as na pilha original
    while (pilhaTemporaria != NULL) {
        Conteudo *msg = pilhaTemporaria;
        pilhaTemporaria = pilhaTemporaria->prox;

        printf("Remetente: %s\nDestinatario: %s\nMensagem: %s\n\n",
               msg->remetente, msg->destinatario, msg->mensagem);

        // Empilha a mensagem de volta na conversa para manter a estrutura original
        msg->prox = conversa->cont;
        conversa->cont = msg;
    }
}
*/