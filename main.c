#include <stdio.h>
#include "usuario.h"
#include "msg.h"

void exibirMenu();

int main() {
    //Usuario *usuarios = NULL;
    int opcao;
    //char nome[50], apelido[30];

    int logado = 0; // Variável para controlar o estado de login (0 = deslogado, 1 = logado)

    do {
        exibirMenu();
        (void) scanf("%d", &opcao); // Tive que mandar ignorar o retorno por conta do compilador

        switch (opcao) {
            case 1:
                if (logado) {
                    printf("Ja esta logado.\n");
                } else {
                    printf("Fazendo login...\n");
                    logado = 1;
                }
                break;
            case 2:
                if (!logado) {
                    printf("Voce precisa estar logado para deslogar.\n");
                } else {
                    printf("Fazendo logout...\n");
                    logado = 0;
                }
                break;
            case 3:
                if (logado) {
                    printf("Adicionando amigo...\n");
                } else {
                    printf("Voce precisa estar logado para adicionar amigos.\n");
                }
                break;
            case 4:
                if (logado) {
                    printf("Enviando mensagem...\n");
                } else {
                    printf("Voce precisa estar logado para enviar mensagens.\n");
                }
                break;
            case 5:
                if (logado) {
                    printf("Visualizando mensagens...\n");
                } else {
                    printf("Voce precisa estar logado para ver mensagens.\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


void exibirMenu() {
    printf("\n===== Menu da Rede Social =====\n");
    printf("1. Login\n");
    printf("2. Logout\n");
    printf("3. Adicionar Amigo\n");
    printf("4. Enviar Mensagem\n");
    printf("5. Ver Mensagens\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}