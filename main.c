#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"
#include "msg.h"
#include "parceria.h"


void exibirListaInversa(Posicoes *lista);
void exibirLista(Posicoes *lista);
void exibirParceriasUsuario(Usuario *usuario);

int main() {

    // Delcaração de variáveis
    void exibirMenu();
    char apelidoEntrada[30];
    char senhaEntrada[30];
    int funcionando = 1;
    int escolha, escolhaPrint, escolhaPedido;
    int flagLogado = 0;
    char apelidoCadastro[30];
    char senhaCadastro[30];
    char nomeCadastro[50];
    char apelidoBusca[30];

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

            Usuario *usuarioLogado = buscarUsuario(usuarios, apelidoEntrada);
            
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

                    break;
                
                case 3:
                    printf("\nEntre com o apelido de quem quer ser parceiro: ");
                    scanf("%s", apelidoBusca);

                    Usuario *busca = NULL;
                    busca = buscarUsuario(usuarios, apelidoBusca);

                    if (busca == NULL){
                        printf("\nUsuário não encontrado. Entre com um nome de usuario valido\n");
                    }else{
                        adicionarPedido(busca->pedido, apelidoEntrada);
                        printf("\nPedido enviado com sucesso!\n");
                    }
                    break;
                
                case 4:
                    pedidos *proximoPedido = mostrarPrimeiroFila(usuarioLogado->pedido);
                    while(proximoPedido != NULL){
                        if(proximoPedido == NULL){
                            printf("Nennhum pedido encontrado!");
                        }else{
                            printf("\n%s deseja ser sua parceira. Aceita (1 - sim/2 -não)?\n", proximoPedido->remetente);
                            scanf("%d", &escolhaPedido);

                            if(escolhaPedido == 1){
                                adicionarParceiro(usuarioLogado->parceiros, proximoPedido->remetente);
                                Usuario *usuarioRemetente = buscarUsuario(usuarios, proximoPedido->remetente);
                                adicionarParceiro(usuarioRemetente->parceiros, usuarioLogado->apelido);
                                removerPedido(usuarioLogado->pedido);
                                printf("\nPedido aceito com sucesso!\n");
                            }else if(escolhaPedido == 2){
                                removerPedido(usuarioLogado->pedido);
                                printf("\nPedido recusado com sucesso!\n");
                            }else{
                                printf("\nInforme um numero valido\n");
                            }

                            proximoPedido = mostrarPrimeiroFila(usuarioLogado->pedido);
                        }
                    }
                    printf("Nennhum pedido encontrado!");
                    break;
                case 9:
                    printf("\nFazendo logout...\n");
                    flagLogado = 0;
                    break;
                default:
                    break;
                }

            } while (escolha != 8 && escolha != 9);

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
        exibirParceriasUsuario(atual);
        atual = atual->prox;
    }
}

// Função para exibir a lista
void exibirListaInversa(Posicoes *lista) {
    Usuario *atual = lista->fim;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        exibirParceriasUsuario(atual);
        atual = atual->ant;
    }
}

// Função para exibir todas as parcerias de um usuário
void exibirParceriasUsuario(Usuario *usuario) {
    if (usuario == NULL) {
        printf("Usuário inválido.\n");
        return;
    }

    if (usuario->parceiros == NULL || usuario->parceiros->inicio == NULL) {
        printf("O usuário %s não possui parcerias.\n", usuario->nome);
        return;
    }

    printf("Parcerias do usuário %s:\n", usuario->nome);
    parceiros *atual = usuario->parceiros->inicio;

    while (atual != NULL) {
        printf("- %s\n", atual->parceiro);
        atual = atual->prox;
    }
}