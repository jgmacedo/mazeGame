#include <stdio.h>
#include <string.h>

/*imports*/

#include "boss.h"
#include "funcoes_auxiliares.h"
#include "jogo.h"
#include "mapWalking20.h"
#include "mapWalking30.h"
#include "mapWalking50.h"
#include "menu.h"
#include "novoPersonagem.h"

int main()
{
    printf("\n============================================\n\n");
    printf("      Seja Bem-Vindo ao Jogo dos Pits!!       \n");
    printf(" 'Onde suas capacidades serão postas à prova' \n");
    printf("         numa épica jornada RPG.              \n");
    printf("\n============================================\n\n");

    menu();

    return 0;
}