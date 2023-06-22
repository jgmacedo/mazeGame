#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map20.c"
#include "funcoes_auxiliares.h"

#define MAP_SIZE 20
#define UNKNOWN_AREA '.'
#define PLAYER_CHAR 'P'
#define WALL_CHAR '#'
#define TRAP_CHAR 'T'
#define TRAP_REVEALED_CHAR 'T'
#define CLEAR_SCREEN() system("clear")
#define MAX_TRAPS 100

typedef struct {
    int x;
    int y;
    int revealed;
} Trap;

Trap traps[10] = {
    {2, 1, 0},
    {7, 2, 0},
    {3, 4, 0},
    {6, 8, 0}, 
    {1, 2, 0}, 
    {4, 5, 0}, 
    {7, 8, 0}, 
    {10, 11, 0}, 
    {13, 14, 0}, 
    {16, 17, 0}

};

int trapCount = 10;  /* quantidade de traps no mapa */

void printMap20(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == playerY && j == playerX) {
                printf("%c ", PLAYER_CHAR);
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}
void generateHiddenMap20(char map[MAP_SIZE][MAP_SIZE], char hiddenMap[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount) {
    int i, j, k;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1) {
                hiddenMap[i][j] = map[i][j];
            } else {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }
            for (k = 0; k < trapCount; k++) {
                if (traps[k].y == i && traps[k].x == j && traps[k].revealed) {
                    hiddenMap[i][j] = TRAP_CHAR;
                    break;
                }
            }
        }
    }
}
void mazeGame20() {
    srand(time(NULL));
    int destreza = 10, inteligencia = 10;
    char hiddenMap[MAP_SIZE][MAP_SIZE];
    int playerX = 1;
    int playerY = 1;
    int selectedMap;
    Trap traps[MAX_TRAPS];
    int trapCount = sizeof(traps) / sizeof(traps[0]);

    if (rand() % 2 == 0) {
        selectedMap = 1;
        generateHiddenMap20(map1, hiddenMap, playerX, playerY, NULL, 0);
    } else {
        selectedMap = 2;
        generateHiddenMap20(map2, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap20(hiddenMap, playerX, playerY, traps, trapCount);

    while (1) {
        printf("Digite uma direção (W, A, S, D) ou 'T' para realizar um teste de percepção ou CTRL + C para sair: \n");
        le_tecla();

        int newX = playerX;
        int newY = playerY;
        int trapChance;

        switch (le_tecla()) {
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
                if (rand() % 100 < trapChance) {
                    printf("Percebeu uma armadilha!\n");
                    int k;
                    for (k = 0; k < trapCount; k++) {
                        int trapX = traps[k].x;
                        int trapY = traps[k].y;
                        if (abs(trapX - playerX) <= 1 && abs(trapY - playerY) <= 1) {
                            traps[k].revealed = 1;
                            /* Update the revealed map with the revealed trap */
                            if (selectedMap == 1) {
                                map1[trapY][trapX] = TRAP_CHAR;
                            } else {
                                map2[trapY][trapX] = TRAP_CHAR;
                            }
                            break;
                        }
                    }
        /* Update the hidden map with the revealed trap */
        generateHiddenMap20(selectedMap == 1 ? map1 : map2, hiddenMap, playerX, playerY, traps, trapCount);
    }
    CLEAR_SCREEN();
    printMap20(hiddenMap, playerX, playerY, traps, trapCount);
    continue;
        }

        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
            ((selectedMap == 1 && map1[newY][newX] != WALL_CHAR) ||
             (selectedMap == 2 && map2[newY][newX] != WALL_CHAR))) {
            playerX = newX;
            playerY = newY;
        }
        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
        ((selectedMap == 1 && map1[newY][newX] == TRAP_CHAR) ||
        (selectedMap == 2 && map2[newY][newX] == TRAP_CHAR))) {
        /* Update the revealed map with the revealed trap */
        if (selectedMap == 1) {
            map1[newY][newX] = TRAP_REVEALED_CHAR;
        } else {
            map2[newY][newX] = TRAP_REVEALED_CHAR;
        }
}

        CLEAR_SCREEN();

        if (selectedMap == 1) {
            generateHiddenMap20(map1, hiddenMap, playerX, playerY, traps, trapCount);
        } else {
            generateHiddenMap20(map2, hiddenMap, playerX, playerY, traps, trapCount);
        }
            printMap20(hiddenMap, playerX, playerY, traps, trapCount);
    }
}

int main() {
    mazeGame20();
    return 0;
}
