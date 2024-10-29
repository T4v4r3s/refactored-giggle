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
int pushConteudo(Conversas *conversa, char *mensagem) {
    Conteudo *novoConteudo = criarConteudo(mensagem);
    if (novoConteudo == NULL) { // Tratando erro de alocação
        return 0;
    }

    // Coloca novoConteudo no topo da pilha
    novoConteudo->prox = conversa->cont; // O novo conteúdo aponta para o antigo topo
    conversa->cont = novoConteudo; // Atualiza o topo da pilha

    return 1;
}


// Função para remover o conteúdo do topo da pilha e retornar a mensagem
char *popConteudo(Conversas *conversa) {
    if (conversa->cont == NULL) {
        return NULL; // Pilha vazia
    }

    // Armazena o conteúdo do topo
    Conteudo *topo = conversa->cont; 

    // Copia a mensagem para uma nova área de memória
    char *mensagem = malloc(strlen(topo->mensagem) + 1);
    if (mensagem != NULL) {
        strcpy(mensagem, topo->mensagem);
    }

    // Atualiza o topo da pilha para o próximo elemento
    conversa->cont = topo->prox; 

    free(topo);  // Libera o antigo topo

    return mensagem;  // Retorna a mensagem copiada
}

// Função para buscar a conversa com base no nome do parceiro
Conversas *buscarConversaPorParceiro(indexConversas *lista, const char *parceiro) {
    Conversas *atual = lista->inicio;

    // Itera pela lista de conversas
    while (atual != NULL) {
        // Compara o nome do parceiro com o parâmetro passado
        if (strncmp(atual->parceiro, parceiro, 30) == 0) {
            // Retorna o ponteiro para a conversa encontrada
            return atual;
        }
        atual = atual->prox;
    }

    // Retorna NULL caso não encontre uma conversa com o parceiro especificado
    return NULL;
}

// Função para buscar a primeira conversa que possui conteúdo
Conversas *buscarPrimeiraConversaComConteudo(indexConversas *lista) {
    Conversas *atual = lista->inicio;

    // Percorre a lista de conversas
    while (atual != NULL) {
        // Verifica se a conversa atual possui conteúdo
        if (atual->cont != NULL) {
            // Retorna o ponteiro para a conversa encontrada
            return atual;
        }
        atual = atual->prox;
    }

    // Retorna NULL caso nenhuma conversa com conteúdo seja encontrada
    return NULL;
}

// Funcoes para dar free

void liberarConteudo(Conteudo *conteudo) {
    while (conteudo != NULL) {
        Conteudo *temp = conteudo;
        conteudo = conteudo->prox;
        free(temp);
    }
}

void liberarConversas(indexConversas *chats) {
    if (chats == NULL) return;
    Conversas *conversa = chats->inicio;
    while (conversa != NULL) {
        Conversas *temp = conversa;
        liberarConteudo(conversa->cont);  // Libera a lista de conteúdo dentro da conversa
        conversa = conversa->prox;
        free(temp);
    }
    free(chats);
}