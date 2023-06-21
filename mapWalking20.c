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
#define CLEAR_SCREEN() system("clear")
#define MAX_TRAPS 100

typedef struct {
    int x;
    int y;
    int revealed;
} Trap;

void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == playerY && j == playerX) {
                printf("%c ", PLAYER_CHAR);
            } else if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1) {
                int k;
                int trapFound = 0;
                for (k = 0; k < trapCount; k++) {
                    if (traps[k].x == j && traps[k].y == i && traps[k].revealed) {
                        printf("%c ", TRAP_CHAR);
                        trapFound = 1;
                        break;
                    }
                }
                if (!trapFound && map[i][j] != WALL_CHAR) {
                    printf("%c ", map[i][j]);
                } else if (!trapFound && map[i][j] == WALL_CHAR) {
                    printf("%c ", WALL_CHAR);
                } else if (trapFound) {
                    printf("%c ", UNKNOWN_AREA);
                }
            } else {
                printf("%c ", UNKNOWN_AREA);
            }
        }
        printf("\n");
    }
}




void generateHiddenMap(char map[MAP_SIZE][MAP_SIZE], char hiddenMap[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1) {
                hiddenMap[i][j] = map[i][j];
            } else {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }

            int k;
            for (k = 0; k < trapCount; k++) {
                if (traps[k].y == i && traps[k].x == j) {
                    hiddenMap[i][j] = UNKNOWN_AREA;  // Oculta armadilhas no mapa
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
    int trapCount = 0;

    if (rand() % 2 == 0) {
        selectedMap = 1;
        generateHiddenMap(map1, hiddenMap, playerX, playerY, NULL, 0);
    } else {
        selectedMap = 2;
        generateHiddenMap(map2, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap(hiddenMap, playerX, playerY, traps, trapCount);



    while (1) {
        printf("Digite uma direção (W, A, S, D) ou 'T' para realizar um teste de percepção ou CTRL + C para sair: \n");
        char input = le_tecla();

        int newX = playerX;
        int newY = playerY;
        int trapChance;


        switch (input) {
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
                if (selectedMap == 1) {
                trapChance = (destreza + inteligencia) * 100 / 20;
                if (rand() % 100 < trapChance) {
                    printf("Percebeu uma armadilha!\n");
                    int k;
                    int trapFound = 0;
                    for (k = 0; k < trapCount; k++) {
                        int trapX = traps[k].x;
                        int trapY = traps[k].y;
                        if ((abs(trapX - playerX) == 1 && trapY == playerY) || (abs(trapY - playerY) == 1 && trapX == playerX)) {
                            traps[k].revealed = 1;
                            trapFound = 1;
                            break;
                        }
                    }
                    if (!trapFound) {
                        traps[trapCount].x = playerX;
                        traps[trapCount].y = playerY;
                        traps[trapCount].revealed = 1;
                        trapCount++;
                    }
                }
                } else {
                    trapChance = (destreza + inteligencia) * 100 / 12;
                    if (rand() % 100 < trapChance) {
                        printf("Percebeu uma armadilha!\n");
                        int k;
                        int trapFound = 0;
                        for (k = 0; k < trapCount; k++) {
                            int trapX = traps[k].x;
                            int trapY = traps[k].y;
                            if ((abs(trapX - playerX) == 1 && trapY == playerY) || (abs(trapY - playerY) == 1 && trapX == playerX)) {
                                traps[k].revealed = 1;
                                trapFound = 1;
                                break;
                            }
                        }
                        if (!trapFound) {
                            traps[trapCount].x = playerX;
                            traps[trapCount].y = playerY;
                            traps[trapCount].revealed = 1;
                            trapCount++;
                        }
                    }
                }
                CLEAR_SCREEN();
                generateHiddenMap(selectedMap == 1 ? map1 : map2, hiddenMap, playerX, playerY, traps, trapCount);
                printMap(hiddenMap, playerX, playerY, traps, trapCount);
                continue;
            default:
                printf("Direção inválida! Tente novamente.\n");
                continue;
        }

        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
            ((selectedMap == 1 && map1[newY][newX] != WALL_CHAR) ||
             (selectedMap == 2 && map2[newY][newX] != WALL_CHAR))) {
            playerX = newX;
            playerY = newY;
        }

        CLEAR_SCREEN();

        if (selectedMap == 1) {
            generateHiddenMap(map1, hiddenMap, playerX, playerY, traps, trapCount);
        } else {
            generateHiddenMap(map2, hiddenMap, playerX, playerY, traps, trapCount);
        }
        printMap(hiddenMap, playerX, playerY, traps, trapCount);
    }
}

