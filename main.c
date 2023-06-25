#include <stdio.h>
#include <string.h>
#include "menu.h"
#ifndef MAP_WALKING
#define MAP_WALKING
#include "mapWalking20.h"
#include "mapWalking30.h"
#include "mapWalking50.h"
#endif
#ifndef NOVOPERSONAGEM_H
#define NOVOPERSONAGEM_H
#include "novoPersonagem.h"
#endif

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