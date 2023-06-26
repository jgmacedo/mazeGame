#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map30.h"
#include "funcoes_auxiliares.h"
#ifndef NOVOPERSONAGEM_H
#define NOVOPERSONAGEM_H
#include "novoPersonagem.h"
#endif


#define MAP_SIZE30 30
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
} Trap30;

Trap30 traps30[25] = {
{1, 8, 0},
{4, 11, 0},
{5, 23, 0},
{5, 3, 0},
{5, 16, 0},
{7, 14, 0},
{10, 27, 0},
{10, 7, 0},
{11, 30, 0},
{12, 1, 0},
{13, 30, 0},
{14, 19, 0},
{15, 1, 0},
{15, 28, 0},
{16, 14, 0},
{18, 17, 0},
{19, 10, 0},
{20, 4, 0},
{21, 17, 0},
{21, 11, 0},
{22, 28, 0},
{23, 18, 0},
{26, 27, 0},
{28, 3, 0},
{29, 14, 0}
};

int trapCount30 = 25; /* quantidade de traps30 no mapa */
int trapCheck30edMap30[MAP_SIZE30][MAP_SIZE30];

void printMap30(char map30[MAP_SIZE30][MAP_SIZE30], int playerX, int playerY, Trap30 traps30[], int trapCount30)
{
    int i, j;
    for (i = 0; i < MAP_SIZE30; i++)
    {
        for (j = 0; j < MAP_SIZE30; j++)
        {
            if (i == playerY && j == playerX)
            {
                printf("%c ", PLAYER_CHAR);
            }
            else
            {
                printf("%c ", map30[i][j]);
            }
        }
        printf("\n");
    }
}

void generateHiddenMap30(char map30[MAP_SIZE30][MAP_SIZE30], char hiddenMap[MAP_SIZE30][MAP_SIZE30], int playerX, int playerY, Trap30 traps30[], int trapCount30)
{
    int i, j, k;
    for (i = 0; i < MAP_SIZE30; i++)
    {
        for (j = 0; j < MAP_SIZE30; j++)
        {
            if (abs(i - playerY) <= 2 && abs(j - playerX) <= 2)/* campo de visão: raio 2 */
            {
                hiddenMap[i][j] = map30[i][j];
            }
            else
            {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }
            for (k = 0; k < trapCount30; k++)
            {
                if (traps30[k].y == i && traps30[k].x == j && traps30[k].revealed)
                {
                    hiddenMap[i][j] = TRAP_CHAR;
                    break;
                }
            }
        }
    }
}

void trapCheck30(int playerX, int playerY, char map30[MAP_SIZE30][MAP_SIZE30], Trap30 traps30[], int trapCount30, int trapCheck30edMap30[MAP_SIZE30][MAP_SIZE30])
{
    int i, j, k;
    char position;

    for (i = playerY - 2; i <= playerY + 2; i++) /* checa armadilhas no campo de visão */
    {
        for (j = playerX - 2; j <= playerX + 2; j++)
        {
            /* scan apenas dentro do mapa para não ter problemas com memória */
            if (i >= 0 && i < MAP_SIZE30 && j >= 0 && j < MAP_SIZE30)
            {
                /* não scanear jogador */
                if (i == playerY && j == playerX)
                    continue;
                position = map30[i][j];

                /* Verifique se a posição corresponde a qualquer uma das posições das armadilhas */
                for (k = 0; k < trapCount30; k++)
                {
                    if (!trapCheck30edMap30[i][j])
                    {
                        if (traps30[k].x == j && traps30[k].y == i) /* Se houver trap */
                        {
                            if (position != WALL_CHAR) /* se não houver parede */
                            {
                                map30[i][j] = TRAP_CHAR;
                            }
                            traps30[k].revealed = 1;
                            trapCheck30edMap30[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void mazeGame30()
{
    srand(time(NULL));
    char map30[MAP_SIZE30][MAP_SIZE30]; /* mapa para ser usado */
    char hiddenMap[MAP_SIZE30][MAP_SIZE30];
    int playerX = 1;
    int playerY = 1;
    int selectedMap;
    int i,k;
    memset(trapCheck30edMap30, 0, sizeof(trapCheck30edMap30));

    if (rand() % 2 == 0)
    {
        selectedMap = 1;
        memcpy(map30, map3, sizeof(map3)); /* copiar mapa do arquivo para o jogo */
        generateHiddenMap30(map30, hiddenMap, playerX, playerY, NULL, 0);
    }
    else
    {
        selectedMap = 2;
        memcpy(map30, map4, sizeof(map4)); /* copiar mapa alternativo do arquivo para o jogo */
        generateHiddenMap30(map30, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap30(hiddenMap, playerX, playerY, traps30, trapCount30);

    while (1)
    {
        printf("Digite uma direção (W, A, S, D) ou 'T' para realizar um teste de percepção ou CTRL + C para sair: \n");
        printf("vida atual: %d\n", personagem.vida);
        le_tecla();
        if (personagem.vida <= 0)
        {
            CLEAR_SCREEN();
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
                trapCheck30(playerX, playerY, map30, traps30, trapCount30, trapCheck30edMap30);
            }
            CLEAR_SCREEN();
            printMap30(hiddenMap, playerX, playerY, traps30, trapCount30);
            personagem.vida--;
            break;
        }

        /* Movimento e condições */
        if (newX >= 0 && newX < MAP_SIZE30 && newY >= 0 && newY < MAP_SIZE30)
        {
            if (map30[newY][newX] == 'X') /* CHEGOU NO BOSS */
            {
                CLEAR_SCREEN();
                printf("\n\nVOCÊ CHEGOU NO FIM. ENFRENTE SEU DESTINO:\n");
                boss();
            }
            if (map30[newY][newX] != WALL_CHAR)
            {
                playerX = newX;
                playerY = newY;
            }
        }

        /* pisou na trap? */
        for (i = 0; i < trapCount30; i++)
        {
            if (traps30[i].x == playerX && traps30[i].y == playerY)
            {
                /* trap acionada */
                personagem.vida -= 5; /* perder vida */
                printf("Você pisou em uma armadilha!");
                traps30[i].revealed = 1;  /* revelar trap */
                map30[playerX][playerY] = TRAP_CHAR;

                break; /* verificar até achar. */
            }
        }
        CLEAR_SCREEN();
        generateHiddenMap30(map30, hiddenMap, playerX, playerY, traps30, trapCount30);
        printMap30(hiddenMap, playerX, playerY, traps30, trapCount30);
    }
}
