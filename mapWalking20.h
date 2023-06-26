#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map20.h"
#include "funcoes_auxiliares.h"

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

#define MAP_SIZE20 20
#define UNKNOWN_AREA '.'
#define PLAYER_CHAR 'P'
#define WALL_CHAR '#'
#define TRAP_CHAR 'T'
#define TRAP_REVEALED_CHAR 'T'
#define CLEAR_SCREEN() system("clear")

typedef struct
{
    int x;
    int y;
    int revealed;
} Trap;

Trap traps[20] = {
    {1, 2, 0},
    {2, 1, 0},
    {3, 4, 0},
    {4, 5, 0},
    {6, 8, 0},
    {7, 2, 0},
    {7, 8, 0},
    {10, 11, 0},
    {13, 14, 0},
    {16, 17, 0},
    {1, 4, 0},
    {3, 2, 0},
    {5, 6, 0},
    {8, 3, 0},
    {9, 7, 0},
    {11, 14, 0},
    {12, 9, 0},
    {14, 16, 0},
    {15, 12, 0},
    {18, 19, 0}

};

int trapCount20 = 20; /* quantidade de traps no mapa */
int trapCheck20edMap[MAP_SIZE20][MAP_SIZE20];

void printMap20(char map[MAP_SIZE20][MAP_SIZE20], int playerX, int playerY, Trap traps[], int trapCount20)
{
    int i, j;
    for (i = 0; i < MAP_SIZE20; i++)
    {
        for (j = 0; j < MAP_SIZE20; j++)
        {
            if (i == playerY && j == playerX)
            {
                printf("%c ", PLAYER_CHAR);
            }
            else
            {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void generateHiddenMap20(char map[MAP_SIZE20][MAP_SIZE20], char hiddenMap[MAP_SIZE20][MAP_SIZE20], int playerX, int playerY, Trap traps[], int trapCount20)
{
    int i, j, k;
    for (i = 0; i < MAP_SIZE20; i++)
    {
        for (j = 0; j < MAP_SIZE20; j++)
        {
            if (abs(i - playerY) <= 2 && abs(j - playerX) <= 2)/* campo de visão: raio 2 */
            {
                hiddenMap[i][j] = map[i][j];
            }
            else
            {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }
            for (k = 0; k < trapCount20; k++)
            {
                if (traps[k].y == i && traps[k].x == j && traps[k].revealed)
                {
                    hiddenMap[i][j] = TRAP_CHAR;
                    break;
                }
            }
        }
    }
}

void trapCheck20(int playerX, int playerY, char map[MAP_SIZE20][MAP_SIZE20], Trap traps[], int trapCount20, int trapCheck20edMap[MAP_SIZE20][MAP_SIZE20])
{
    int i, j, k;
    char position;

    for (i = playerY - 2; i <= playerY + 2; i++) /* checa armadilhas no campo de visão */
    {
        for (j = playerX - 2; j <= playerX + 2; j++)
        {
            /* scan apenas dentro do mapa para não ter problemas com memória */
            if (i >= 0 && i < MAP_SIZE20 && j >= 0 && j < MAP_SIZE20)
            {
                /* não scanear jogador */
                if (i == playerY && j == playerX)
                    continue;
                position = map[i][j];

                /* Verifique se a posição corresponde a qualquer uma das posições das armadilhas */
                for (k = 0; k < trapCount20; k++)
                {
                    if (!trapCheck20edMap[i][j])
                    {
                        if (traps[k].x == j && traps[k].y == i) /* Se houver trap */
                        {
                            if (position != WALL_CHAR) /* se não houver parede */
                            {
                                map[i][j] = TRAP_CHAR;
                            }
                            traps[k].revealed = 1;
                            trapCheck20edMap[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void mazeGame20()
{
    srand(time(NULL));
    char map[MAP_SIZE20][MAP_SIZE20]; /* mapa para ser usado */
    char hiddenMap[MAP_SIZE20][MAP_SIZE20];
    int playerX = 1;
    int playerY = 1;
    int selectedMap;
    int i,k;
    memset(trapCheck20edMap, 0, sizeof(trapCheck20edMap));

    if (rand() % 2 == 0)
    {
        selectedMap = 1;
        memcpy(map, map1, sizeof(map1)); /* copiar mapa do arquivo para o jogo */
        generateHiddenMap20(map, hiddenMap, playerX, playerY, NULL, 0);
    }
    else
    {
        selectedMap = 2;
        memcpy(map, map2, sizeof(map2)); /* copiar mapa alternativo do arquivo para o jogo */
        generateHiddenMap20(map, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap20(hiddenMap, playerX, playerY, traps, trapCount20);

    while (1)
    {
        printf("Digite uma direção (W, A, S, D) ou 'T' para realizar um teste de percepção ou CTRL + C para sair: \n");
        printf("vida atual: %d\n", personagem.vida);
        le_tecla();
        if (personagem.vida <= 0)
        {
            system("clear");
            printf("\n\n\nGAME OVER, SUA VIDA ACABOU.\n\n\n");
            exit(0);
        }
        int newX = playerX;
        int newY = playerY;
        int trapChance;

        switch (le_tecla())
        {
        case 'w':
        case 'W':
            newY = playerY - 1;
            break;
        case 'a':
        case 'A':
            newX = playerX - 1;
            break;
        case 's':
        case 'S':
            newY = playerY + 1;
            break;
        case 'd':
        case 'D':
            newX = playerX + 1;
            break;
        case 't':
        case 'T':
            if (personagem.profissao == 3){
                trapChance = (personagem.destreza + personagem.inteligencia) * 100 / 12;
            }else {
                trapChance = (personagem.destreza + personagem.inteligencia) * 100 / 20;
            }

            if (rand() % 100 < trapChance)
            {
                trapCheck20(playerX, playerY, map, traps, trapCount20, trapCheck20edMap);
            }
            CLEAR_SCREEN();
            printMap20(hiddenMap, playerX, playerY, traps, trapCount20);
            personagem.vida--;
            break;
        }

        /* Movimento e condições */
        if (newX >= 0 && newX < MAP_SIZE20 && newY >= 0 && newY < MAP_SIZE20)
        {
            if (map[newY][newX] == 'X') /* CHEGOU NO BOSS */
            {
                CLEAR_SCREEN();
                printf("\n\nVOCÊ CHEGOU NO FIM. ENFRENTE SEU DESTINO:\n");
                boss();
            }
            if (map[newY][newX] != WALL_CHAR)
            {
                playerX = newX;
                playerY = newY;
            }
        }

        /* pisou na trap? */
        for (i = 0; i < trapCount20; i++)
        {
            if (traps[i].x == playerX && traps[i].y == playerY)
            {
                /* trap acionada */
                personagem.vida -= 5; /* perder vida */
                printf("Você pisou em uma armadilha!");
                traps[i].revealed = 1;  /* revelar trap */
                map[playerX][playerY] = TRAP_CHAR;

                break; /* verificar até achar. */
            }
        }
        CLEAR_SCREEN();
        generateHiddenMap20(map, hiddenMap, playerX, playerY, traps, trapCount20);
        printMap20(hiddenMap, playerX, playerY, traps, trapCount20);
    }
}
