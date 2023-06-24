#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*imports*/
#ifndef MAP_WALKING
#define MAP_WALKING
#include "mapWalking20.h"
#include "mapWalking30.h"
#include "mapWalking50.h"
#endif
#ifndef NOVO_H
#define NOVO_H
#include "novoPersonagem.h"
#endif

void jogo()
{
    struct boneco personagem;
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
            mazeGame20();
            break;
        case 2:
            mazeGame30();
            break;
        case 3:
            mazeGame50();
            break;
        default:
            printf("\n* Opção Inválida! Tente Novamente... *\n");
            continue;
        }
    }
}