#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*imports*/
#include "mapWalking20.h"
#include "mapWalking30.h"
#include "mapWalking50.h"

void jogo()
{
    int dificuldade;

    while (dificuldade != 1 || dificuldade != 2 || dificuldade != 3)
    {
        printf("Ah, viajante destemido, antes de embarcar em sua jornada épica, você precisa decidir o destino de sua coragem. Permita-me perguntar: qual trilha você deseja trilhar?\n");
        printf("Escolha o nivel de dificuldade:\n");
        printf("1.Fácil\n");
        printf("2.Médio\n");
        printf("3.Dificuldade\n");
        printf("-> ");
        scanf("%d", &dificuldade);
        printf(": ");
        switch (dificuldade)
        {
        case 1:
            printf("\nApós um longo dia de exploração na floresta mística de FAVELA DOS PITS, você se depara com um misterioso artefato antigo.\n");
            printf("Ao tocá-lo, uma estranha energia o envolve e, de repente, você se vê transportado para um labirinto encantado. Acredita-se que somente o escolhido poderá desvendar seus segredos e encontrar o caminho de volta para casa. \n");
            printf("Agora, com coragem e determinação, você se posiciona na entrada do labirinto, pronto para enfrentar os desafios que aguardam.\n");
            printf("\n");
            mazeGame20();
            break;
        case 2:
            printf("\nEm sua busca por conhecimento e aventura, você decidiu explorar as ruínas ancestrais de FAVELA DOS PITS.\n");
            printf("Enquanto desbravava os corredores esquecidos, uma armadilha mágica é ativada, teleportando você para um labirinto enigmático. Os antigos registros mencionam que apenas um verdadeiro homem será capaz de decifrar os segredos ocultos nesse emaranhado de passagens. \n");
            printf("Agora, no início do labirinto, você se prepara para enfrentar os desafios que se apresentam diante de você.\n");
            printf("\n");
            mazeGame30();
            break;
        case 3:
            printf("\nComo um renomado aventureiro em busca de fama e glória, você se aventura nos confins de FAVELA DOS PITS, onde lendas e perigos se entrelaçam.\n");
            printf("Durante uma expedição ousada, você é capturado por uma entidade sombria e transportado para um labirinto enigmático, conhecido por aprisionar os mais destemidos desbravadores. Dizem que apenas um verdadeiro homem, destinado a superar todas as adversidades, terá a chance de escapar.\n");
            printf("Agora, ao iniciar sua jornada no labirinto, você se prepara para provar seu valor e encontrar o caminho de volta à liberdade.\n");
            printf("\n");
            mazeGame50();
            break;
        default:
            printf("\n* Opção Inválida! Tente Novamente... *\n");
            continue;
        }
    }
}