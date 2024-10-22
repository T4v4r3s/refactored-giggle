#include <stdio.h>
#include "usuario.h"
#include "mensagem.h"
#include "pedido.h"

int main() {
    Usuario *usuarios = NULL;
    int opcao;
    char nome[50], apelido[30], apelidoAlvo[30], texto[100];

    do {
        printf("1) Cadastrar usuário\n2) Listar usuários\n3) Pedir parceria\n4) Avaliar pedidos\n5) Enviar mensagem\n6) Ler mensagens\n0) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Apelido: ");
                scanf("%s", apelido);
                cadastrarUsuario(&usuarios, nome, apelido);
                break;
            case 2:
                listarUsuarios(usuarios);
                break;
            case 3:
                printf("Seu apelido: ");
                scanf("%s", apelido);
                printf("Apelido de quem quer ser parceiro: ");
                scanf("%s", apelidoAlvo);
                pedirParceria(usuarios, apelido, apelidoAlvo);
                break;
            case 4:
                printf("Seu apelido: ");
                scanf("%s", apelido);
                avaliarPedidos(usuarios, apelido);
                break;
            case 5:
                printf("Seu apelido: ");
                scanf("%s", apelido);
                printf("Apelido de quem quer enviar mensagem: ");
                scanf("%s", apelidoAlvo);
                printf("Mensagem: ");
                scanf(" %[^\n]", texto);
                enviarMensagem(usuarios, apelido, apelidoAlvo, texto);
                break;
            case 6:
                printf("Seu apelido: ");
                scanf("%s", apelido);
                lerMensagens(usuarios, apelido);
                break;
        }
    } while (opcao != 0);

    return 0;
}
