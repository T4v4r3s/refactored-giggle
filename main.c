#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"
#include "msg.h"
#include "parceria.h"


void exibirListaInversa(Posicoes *lista);
void exibirLista(Posicoes *lista);
void exibirParceriasUsuario(Usuario *usuario);
void exibirMensagens(Conversas *chats);
void sugerirParcerias(Posicoes *listaUsuarios, Usuario *usuarioAtual);
int jaEhParceiro(indexParceiros *listaUsuario, const char *parceiro);

int main() {

    // Delcaracao de variaveis
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
    char mensagem[300];

    // Inicializacao da lista de usuarios
    Posicoes *usuarios = malloc(sizeof(Posicoes));
    if (usuarios == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }
    inicializarLista(usuarios);
    
    
    while (funcionando){

        printf("---------------------------");
        printf("    \nBem-Vindo\n\n");
        printf("   -- Escolha uma opcao --\n\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar Usuario\n");
        printf("3 - SAIR!\n");
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
        case 3:
            funcionando = 0;  // Sair do loop de execucao 
            printf("Desligando o programa...\n\n Obrigado por usar!\n");
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
                                // Adiciona o parceiro na lista do usuario atual
                                adicionarParceiro(usuarioLogado->parceiros, proximoPedido->remetente);

                                // Adiciona um chat ao usuario atual sendo o remetendo esse novo parceiro
                                if(adicionarConversas(usuarioLogado->chats, proximoPedido->remetente)){
                                    printf("\n%s conectado com chat ao %s", usuarioLogado->apelido, proximoPedido->remetente);
                                }else{
                                    printf("\n\n\n ERRO AO ADICIONAR CHAT, PROGRAMA PARANDO!....");
                                    return 1;
                                }
                                
                                // Procura qual eh a estrutura do parceiro a ser adicionado
                                Usuario *usuarioRemetente = buscarUsuario(usuarios, proximoPedido->remetente);
                                
                                // Adiciona o usuario atual na lista de parceiros
                                adicionarParceiro(usuarioRemetente->parceiros, usuarioLogado->apelido);
                                
                                // Adiciona um chat ao parceiro sendo o remetente o usuario atual
                                if(adicionarConversas(usuarioRemetente->chats, usuarioLogado->apelido)){
                                    printf("\n%s conctado com chat ao %s", usuarioRemetente->apelido, usuarioLogado->apelido);
                                }else{
                                    printf("\n\n\n ERRO AO ADICIONAR CHAT, PROGRAMA PARANDO!....");
                                    return 1;
                                }

                                // Remove o pedido uma vez que foi aceito
                                removerPedido(usuarioLogado->pedido);
                                printf("\nPedido aceito com sucesso!\n");
                            }else if(escolhaPedido == 2){
                                // Uma vez que recusou, apenas o pedido eh excluido
                                removerPedido(usuarioLogado->pedido);
                                printf("\nPedido recusado com sucesso!\n");
                            }else{
                                printf("\nInforme um numero valido\n");
                            }

                            proximoPedido = mostrarPrimeiroFila(usuarioLogado->pedido);
                        }
                    }
                    printf("\nNennhum pedido encontrado!\n");
                    break;
                case 5:
                    printf("\n\nFale o apelido do usuário que gostaria de mandar msg: ");
                    while ((getchar()) != '\n'); // Limpa o buffer até a nova linha
                    fgets(apelidoBusca, sizeof(apelidoBusca), stdin);
                    // Remove o newline se existir
                    apelidoBusca[strcspn(apelidoBusca, "\n")] = 0;
                    
                    if(buscarParceiro(usuarioLogado->parceiros, apelidoBusca)!=NULL){
                        Usuario *remetente = buscarUsuario(usuarios, apelidoBusca);
                        
                        Conversas *conversa = buscarConversaPorParceiro(remetente->chats, usuarioLogado->nome);

                        printf("\n Informe a mensagem a ser enviada: ");
                        fgets(mensagem, sizeof(mensagem), stdin);
                        mensagem[strcspn(mensagem, "\n")] = 0;  // Remove o newline

                        if(pushConteudo(conversa, mensagem)){
                            printf("\nMensagem enviada com sucesso!\n\n");
                        }else{
                            printf("\n Erro interno ao enviar mensagem !\n\n");
                            return 1;
                        }
                    }else{
                        printf("\nParceiro não encontrado!\n");
                    }

                    break;
                case 6:
                    
                    Conversas *chats = buscarPrimeiraConversaComConteudo(usuarioLogado->chats);


                    if(chats == NULL){
                        printf("\n Você não tem mais mensagens\n");
                    }else{
                        while (chats != NULL) {
                            // Exibe todas as mensagens da conversa atual
                            exibirMensagens(chats);

                            // Avança para a próxima conversa
                            chats = chats->prox; // Supondo que 'prox' é o campo que aponta para a próxima conversa
                        }
                    }

                    break;
                case 7:
                    sugerirParcerias(usuarios, usuarioLogado);
                    break;

                case 8:

                    printf("\n\n\nReiniciando o sistema....\n\n\n");

                    // Liberação de cada lista dentro de cada usuário
                    Usuario *usuario = usuarios->inicio;
                    while (usuario != NULL) {
                        Usuario *temp = usuario;

                        // Libera as conversas do usuário
                        liberarConversas(usuario->chats);
                        
                        // Libera a fila de pedidos do usuário
                        liberarPedidos(usuario->pedido);
                        
                        // Libera a lista de parceiros do usuário
                        liberarParceiros(usuario->parceiros);
                        
                        usuario = usuario->prox;
                        free(temp);  // Libera o próprio nó de usuário
                    }

                    // Libera a estrutura da lista de usuários
                    free(usuarios);

                    usuarioLogado = NULL;
                    flagLogado = 0;

                    // Inicializacao da lista de usuarios
                    Posicoes *usuarios = malloc(sizeof(Posicoes));
                    if (usuarios == NULL) {
                        fprintf(stderr, "Erro de alocação de memória.\n");
                        return 1;
                    }
                    inicializarLista(usuarios);

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
    

    // Libera a estrutura da lista de usuários
    free(usuarios);



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

// Funcao para exibir a lista
void exibirLista(Posicoes *lista) {
    Usuario *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        exibirParceriasUsuario(atual);
        atual = atual->prox;
    }
}

// Funcao para exibir a lista
void exibirListaInversa(Posicoes *lista) {
    Usuario *atual = lista->fim;
    while (atual != NULL) {
        printf("Nome: %s, Apelido: %s\n", atual->nome, atual->apelido);
        exibirParceriasUsuario(atual);
        atual = atual->ant;
    }
}

// Funcao para exibir todas as parcerias de um usuario
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

// Funcao para exibir (e excluir) as mensagens
void exibirMensagens(Conversas *chats) {
    char *mensagem;

    printf("\n Suas mensagens são:\n");

    do {
        mensagem = popConteudo(chats);
        if (mensagem != NULL) {
            printf("\n(%s)-> %s \n",chats->parceiro, mensagem);
            // Opcionalmente, liberar a memoria de conteudo aqui, se necessario.
        }
    } while (chats->cont != NULL);
}

// Funcao para verificar se um parceiro ja eh parceiro do usuario
int jaEhParceiro(indexParceiros *listaUsuario, const char *parceiro) {
    for (parceiros *p1 = listaUsuario->inicio; p1 != NULL; p1 = p1->prox) {
        if (strcmp(p1->parceiro, parceiro) == 0) {
            return 1; // Ja eh parceiro
        }
    }
    return 0; // Nao eh parceiro
}

// Funcao para mostrar sugestoes de amizade
void sugerirParcerias(Posicoes *listaUsuarios, Usuario *usuarioAtual) {
    // Acessar a lista de parceiros do usuario atual
    indexParceiros *listaUsuarioAtual = usuarioAtual->parceiros;

    // Vetor para armazenar sugestoes
    char *sugestoes[500];
    int numSugestoes = 0;

    // Para cada parceiro do usuario atual
    parceiros *atualParceiro = listaUsuarioAtual->inicio;
    while (atualParceiro != NULL) {
        // Buscar o usuario correspondente ao parceiro
        Usuario *parceiro = buscarUsuario(listaUsuarios, atualParceiro->parceiro);
        if (parceiro != NULL) {
            // Para cada parceiro do parceiro encontrado
            parceiros *parceirosDoParceiro = parceiro->parceiros->inicio;
            while (parceirosDoParceiro != NULL) {
                // Verificar se o parceiro do parceiro nao eh o usuario atual
                if (strcmp(parceirosDoParceiro->parceiro, usuarioAtual->apelido) != 0) {
                    // Verificar se nao eh um parceiro do usuario atual
                    if (buscarParceiro(listaUsuarioAtual, parceirosDoParceiro->parceiro) == NULL) {
                        // Adicionar a lista de sugestões
                        sugestoes[numSugestoes] = strdup(parceirosDoParceiro->parceiro);
                        numSugestoes++;
                    }
                }
                parceirosDoParceiro = parceirosDoParceiro->prox;
            }
        }
        atualParceiro = atualParceiro->prox;
    }

    // Imprimir as sugestoes
    if (numSugestoes > 0) {
        printf("Sugestão de novas parcerias: ");
        for (int i = 0; i < numSugestoes; i++) {
            printf("%s", sugestoes[i]);
            if (i < numSugestoes - 1) {
                printf(", "); // Adicionar virgula entre as sugestoes
            }
            free(sugestoes[i]); // Liberar a memoria alocada
        }
        printf("\n");
    } else {
        printf("Não há novas parcerias sugeridas.\n");
    }
}



