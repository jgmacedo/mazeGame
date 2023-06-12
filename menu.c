#include <stdio.h>
#include <stdlib.h>

int main()
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
            personagemCriado = 1;
            printf("chamar a funcao criacao de personagem\n");
            break;
        case 2:
            if (personagemCriado == 1)
            {
                printf("chamar a funcao jogo\n");
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