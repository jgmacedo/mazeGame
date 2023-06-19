#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map20.c"
#include "funcoes_auxiliares.h"

#define MAP_SIZE 20
#define UNKNOWN_AREA '.'
#define PLAYER_CHAR 'P'
#define WALL_CHAR '#'
#define CLEAR_SCREEN system("clear")
#define TRAP_CHAR 'T'


void generateHiddenMap(char map[MAP_SIZE][MAP_SIZE], char hiddenMap[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1) {
                hiddenMap[i][j] = map[i][j];  /* Show a limited view of the map */
            } else {
                hiddenMap[i][j] = UNKNOWN_AREA;  /* Hidden area */
            }

            /*  Hide the trap if it hasn't been perceived */
            if (hiddenMap[i][j] == TRAP_CHAR && map[i][j] != TRAP_CHAR) {
                hiddenMap[i][j] = UNKNOWN_AREA;
            }
        }
    }
}


void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    int i,j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == playerY && j == playerX) {
                printf("%c ", PLAYER_CHAR);  /* Mostra a posição atual do jogador */
            } else if (abs(i - playerY) <= 1 && abs(j - playerX) <= 1) {
                printf("%c ", map[i][j]);  /* Mostra uma visão limitada do mapa */
            } else {
                printf("%c ", UNKNOWN_AREA);  /* Área oculta */
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char hiddenMap[MAP_SIZE][MAP_SIZE];

    int playerX = 1;  /* Posição inicial do jogador */
    int playerY = 1;
    int selectedMap;
    float trapChance, destreza = 10, inteligencia = 10; /* necessário declarar dentro do main ou do menu os valores de destreza e inteligência como float */
    
    if (rand() % 2 == 0) {
        selectedMap = 1;
        generateHiddenMap(map1, hiddenMap, playerX, playerY);
    } else {
        selectedMap = 2;
        generateHiddenMap(map2, hiddenMap, playerX, playerY);
    }

    printMap(hiddenMap, playerX, playerY);
    
        while (1) {
        printf("Digite uma direção (W, A, S, D) ou CTRL + C para sair: \n");
        le_tecla();

        int newX = playerX;
        int newY = playerY;

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
            /*teste de trap*/
            if (selectedMap == 1) {
                trapChance = (destreza + inteligencia) * 100 / 20;
                if (rand() % 100 < trapChance) {
                    printf("Percebeu uma armadilha!\n");
                        map1[playerY][playerX] = TRAP_CHAR;
                    }
                } else {
                    trapChance = (destreza + inteligencia) * 100 / 12;
                    if (rand() % 100 < trapChance) {
                        printf("Percebeu uma armadilha!\n");
                        map2[playerY][playerX] = TRAP_CHAR;
                    }
                }
            default:
                printf("Direção inválida! Tente novamente.\n");
                continue;
            }
            if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE &&
                ((selectedMap == 1 && map1[newY][newX] != WALL_CHAR) ||
                 (selectedMap == 2 && map2[newY][newX] != WALL_CHAR)))
            {
                playerX = newX;
                playerY = newY;
            }
            CLEAR_SCREEN;

        if (selectedMap == 1){
                generateHiddenMap(map1, hiddenMap, playerX, playerY); /* Usando map1 */
        } else {
            generateHiddenMap(map2, hiddenMap, playerX, playerY);  /* Usando map2 */
        }
        printMap(hiddenMap, playerX, playerY);
    }

    return 0;
}
