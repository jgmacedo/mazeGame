#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map20.c"
#include "funcoes_auxiliares.h"

#define MAP_SIZE 20
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

Trap traps[10] = {
    {1, 2, 0},
    {2, 1, 0},
    {3, 4, 0},
    {4, 5, 0},
    {6, 8, 0},
    {7, 2, 0},
    {7, 8, 0},
    {10, 11, 0},
    {13, 14, 0},
    {16, 17, 0}

};

int trapCount = 10; /* quantidade de traps no mapa */
int trapCheckedMap[MAP_SIZE][MAP_SIZE];

void printMap20(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount)
{
    int i, j;
    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
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
void generateHiddenMap20(char map[MAP_SIZE][MAP_SIZE], char hiddenMap[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount)
{
    int i, j, k;
    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
        {
            if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1)
            {
                hiddenMap[i][j] = map[i][j];
            }
            else
            {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }
            for (k = 0; k < trapCount; k++)
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
void trapCheck(int playerX, int playerY, char map[MAP_SIZE][MAP_SIZE], Trap traps[], int trapCount, int trapCheckedMap[MAP_SIZE][MAP_SIZE])
{
    int i, j, k;
    char position;

    for (i = playerY - 1; i <= playerY + 1; i++)
    {
        for (j = playerX - 1; j <= playerX + 1; j++)
        {
         /* Verifique se as coordenadas atuais estão dentro dos limites do mapa */
            if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE)
            {
             /* Pule a posição do jogador */
                if (i == playerY && j == playerX)
                    continue;
                position = map[i][j];
                
             /* Verifique se a posição corresponde a qualquer uma das posições das armadilhas */
                for (k = 0; k < trapCount; k++)
                {
            if (!trapCheckedMap[i][j])
            {                    
                    if (traps[k].x == j && traps[k].y == i)/* Se houver trap */
                    {
                        if(position != WALL_CHAR)/* se não houver parede */
                        {
                            map[i][j] = TRAP_CHAR;
                        }
                    traps[k].revealed = 1;
                    trapCheckedMap[i][j] = 1;
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
    int destreza = 5, inteligencia = 5;
    char hiddenMap[MAP_SIZE][MAP_SIZE];
    int playerX = 1;
    int playerY = 1;
    int selectedMap;
    int trapCount = sizeof(traps) / sizeof(traps[0]);
    int trapCheckedMap[MAP_SIZE][MAP_SIZE] = {0};
    int vida = 100;
    memset(trapCheckedMap, 0, sizeof(trapCheckedMap));

    if (rand() % 2 == 0)
    {
        selectedMap = 1;
        generateHiddenMap20(map1, hiddenMap, playerX, playerY, NULL, 0);
    }
    else
    {
        selectedMap = 2;
        generateHiddenMap20(map2, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap20(hiddenMap, playerX, playerY, traps, trapCount);

    while (1)
    {
        printf("Digite uma direção (W, A, S, D) ou 'T' para realizar um teste de percepção ou CTRL + C para sair: \n");
        printf("vida atual: %d\n", vida);
        le_tecla();

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
                trapChance = (destreza + inteligencia) * 100 / 12;
                if (rand() % 100 > trapChance)
                {
                    trapCheck(playerX, playerY, map1, traps, trapCount, trapCheckedMap);
                }
                CLEAR_SCREEN();
                printMap20(hiddenMap, playerX, playerY, traps, trapCount);
                vida --;
                break;
        }

        /* Movimento e condições */
        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
            ((selectedMap == 1 && map1[newY][newX] != WALL_CHAR) ||
             (selectedMap == 2 && map2[newY][newX] != WALL_CHAR)))
        {
            playerX = newX;
            playerY = newY;
        }
        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
            ((selectedMap == 1 && map1[newY][newX] == TRAP_CHAR) ||
             (selectedMap == 2 && map2[newY][newX] == TRAP_CHAR)))
        {
            /* colocar a trap */
            if (selectedMap == 1)
            {
                map1[newY][newX] = TRAP_REVEALED_CHAR;
            }
            else
            {
                map2[newY][newX] = TRAP_REVEALED_CHAR;
            }
        }

        CLEAR_SCREEN();

        if (selectedMap == 1)
        {
            generateHiddenMap20(map1, hiddenMap, playerX, playerY, traps, trapCount);
        }
        else
        {
            generateHiddenMap20(map2, hiddenMap, playerX, playerY, traps, trapCount);
        }
        printMap20(hiddenMap, playerX, playerY, traps, trapCount);
        
    }
}

int main()
{
    mazeGame20();
    return 0;
}
