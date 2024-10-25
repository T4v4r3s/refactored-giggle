#include <stdio.h>
#include "usuario.h"


int main() {
    Usuario *usuarios = NULL;
    int opcao;
    char nome[50], apelido[30];

    do{

        printf("1 - Login");
        printf("2 - Cadastro");
        printf("3 - Sair");

        scanf("%d", &opcao);

        if(opcao == 1){
            //Login

            


        }else if (opcao == 2){
            //Cadastro
        }else if (opcao > 3){
            printf("Opção inválida");
        }
        
    } while (opcao == 3);
    


    return 0;
}
