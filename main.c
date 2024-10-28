#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"
#include "msg.h"


void exibirListaInversa(Posicoes *lista);
void exibirLista(Posicoes *lista);

int main() {

    // Delcaração de variáveis
    void exibirMenu();
    char apelidoEntrada[30];
    char senhaEntrada[30];
    int funcionando = 1;
    int escolha, escolhaPrint;
    int flagLogado = 0;
    char apelidoCadastro[30];
    char senhaCadastro[30];
    char nomeCadastro[50];

    // Inicialização da lista de usuários
    Posicoes *usuarios = malloc(sizeof(Posicoes));
    if (usuarios == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }
    inicializarLista(usuarios);
    
    
    while (funcionando){

        printf("---------------------------");
        printf("    \nBem-Vindo\n\n");
        printf("    Escolha uma opcao\n\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar Usuario\n");
        printf("---------------------------\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("===== Login =====\n");
            printf("Digite o nome de usuário: ");
            scanf("%s", apelidoEntrada);
            printf("Digite a senha: ");
            scanf("%s", senhaEntrada);

            if(login(usuarios, apelidoEntrada, senhaEntrada)){
                printf("\nLogin bem sucedido!\n");
                flagLogado = 1;
            }else{
                printf("\nUsuaio ou senha invalidos \n");
            }

            break;
        case 2:

            printf("Informe o nome: ");
            scanf("%s", nomeCadastro);
            printf("\nInforme o apelido: ");
            scanf("%s", apelidoCadastro);
            printf("\nInforme a senha: ");
            scanf("%s", senhaCadastro);
            
            if(criarEInserirUsuario(usuarios, nomeCadastro, apelidoCadastro, senhaCadastro)){
                printf("Usuario criado com sucesso\n");
            }else{
                printf("Erro ao criar usuario\n");
            }


            break;
        default:
            printf("Informe um numero valido");
            break;
        }

        if(flagLogado){
            
            do{
                exibirMenu();
                scanf("%d", &escolha);

                switch (escolha){
                case 1:
                    
                    printf("Informe o nome: ");
                    scanf("%s", nomeCadastro);
                    printf("\nInforme o apelido: ");
                    scanf("%s", apelidoCadastro);
                    printf("\nInforme a senha: ");
                    scanf("%s", senhaCadastro);
                    
                    if(criarEInserirUsuario(usuarios, nomeCadastro, apelidoCadastro, senhaCadastro)){
                        printf("Usuario criado com sucesso\n");
                    }else{
                        printf("Erro ao criar usuario\n");
                    }
                    break;
                
                case 2:
                    printf("\n1- Ordem alfabética\n");
                    printf("\n2- Ordem alfabética inversa\n");

                    scanf("%d", &escolhaPrint);

                    if (escolhaPrint == 1){
                        exibirLista(usuarios);
                    }else if(escolhaPrint == 2){
                        exibirListaInversa(usuarios);
                    }else{
                        printf("\n Numero Invalido\n");
                    }
                

                default:
                    break;
                }

            } while (escolha != 8 || escolha != 9);

        }
    
    

    }
    





    return 0;
}


void exibirMenu() {
    printf("\nCaro usuário, suas opções são:\n");
    printf("1) Cadastrar um usuário\n");
    printf("2) Listar usuários cadastrados e suas informações\n");
    printf("3) Pedir para ser parceiro de um usuário\n");
    printf("4) Avaliar lista de pedidos de parceria\n");
    printf("5) Enviar mensagem para um parceiro\n");
    printf("6) Ver mensagens recebidas\n");
    printf("7) Sugerir novas parcerias\n");
    printf("8) Reinicializar sistema\n");
    printf("9) Logout\n\n");
    printf("O que deseja fazer? \n\n");
}

// Função para exibir a lista
void exibirLista(Posicoes *lista) {
    Usuario *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        atual = atual->prox;
    }
}

// Função para exibir a lista
void exibirListaInversa(Posicoes *lista) {
    Usuario *atual = lista->fim;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        atual = atual->ant;
    }
}