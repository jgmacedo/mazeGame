#include <stdio.h>
#include <stdlib.h>

/* imports */
#include "menu.h"
#include "jogo.h"
#include "novoPersonagem.h"

void menu()
{
    int opcoesIniciais;
    int personagemCriado = 0;
    int sairDoJogo = 0;

    while (sairDoJogo == 0)
    {
        /*======== MENU DE ENTRADA (opcoes usuario) =================*/
        printf("***********************************\n\n");
        printf("Escolha qual opção deseja executar:\n");
        printf("1 - Criar Personagem.\n");
        printf("2 - Entrar no jogo.\n");
        printf("0 - Sair.\n\n");
        printf("***********************************\n");
        printf("Digite a escolha abaixo:\n");

        /*opcoes do menu que o usuario pode escolher*/
        scanf("%d", &opcoesIniciais);
        switch (opcoesIniciais)
        {
        case 1:
            printf("Então vamos criar seu personagem para esta jornada íncrivel!\n");
            novoPersonagem();
            personagemCriado = 1;
            break;
        case 2:
            if (personagemCriado == 1)
            {
                system("clear");
                jogo();
            }
            else
            {
                system("clear");
                printf("\n* Primeiro crie seu personagem *\n\n");
                continue;
            }
        case 0:
            printf("Voce saiu do jogo\n");
            sairDoJogo = 1;
            break;
        default:
            system("clear");
            printf("\n* Opção Inválida! Tente Novamente *\n\n");
            continue;
        }
    }
}