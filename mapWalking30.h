#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map30.h"
#include "funcoes_auxiliares.h"


#define MAP_SIZE 30
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

Trap traps[25] = {
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
struct Personagem
{
    int vida;
    int raca;
    int alinhamento;
    int profissao;
    char historiaPrevia[401];
    int porte;
    int forca;
    int destreza;
    int inteligencia;
    int constituicao;
};
int trapCount = 25; /* quantidade de traps no mapa */
int trapCheckedMap[MAP_SIZE][MAP_SIZE];

void printMap30(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount)
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

void generateHiddenMap30(char map[MAP_SIZE][MAP_SIZE], char hiddenMap[MAP_SIZE][MAP_SIZE], int playerX, int playerY, Trap traps[], int trapCount)
{
    int i, j, k;
    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
        {
            if (abs(i - playerY) <= 2 && abs(j - playerX) <= 2)/* campo de visão: raio 2 */
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

    for (i = playerY - 2; i <= playerY + 2; i++) /* checa armadilhas no campo de visão */
    {
        for (j = playerX - 2; j <= playerX + 2; j++)
        {
            /* scan apenas dentro do mapa para não ter problemas com memória */
            if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE)
            {
                /* não scanear jogador */
                if (i == playerY && j == playerX)
                    continue;
                position = map[i][j];

                /* Verifique se a posição corresponde a qualquer uma das posições das armadilhas */
                for (k = 0; k < trapCount; k++)
                {
                    if (!trapCheckedMap[i][j])
                    {
                        if (traps[k].x == j && traps[k].y == i) /* Se houver trap */
                        {
                            if (position != WALL_CHAR) /* se não houver parede */
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

void mazeGame30(struct Personagem personagem)
{
    srand(time(NULL));
    char map[MAP_SIZE][MAP_SIZE]; /* mapa para ser usado */
    char hiddenMap[MAP_SIZE][MAP_SIZE];
    int playerX = 1;
    int playerY = 1;
    int selectedMap;
    int i,k;
    memset(trapCheckedMap, 0, sizeof(trapCheckedMap));
    /* apenas para teste: APAGAR */
    
    personagem.raca = 1;
    personagem.alinhamento = 1;
    personagem.profissao = 1;
    personagem.porte = 1;
    personagem.forca = 1;
    personagem.destreza = 1;
    personagem.inteligencia = 1;
    personagem.constituicao = 1;
    personagem.vida = personagem.constituicao * 20; 

    if (rand() % 2 == 0)
    {
        selectedMap = 1;
        memcpy(map, map1, sizeof(map1)); /* copiar mapa do arquivo para o jogo */
        generateHiddenMap30(map, hiddenMap, playerX, playerY, NULL, 0);
    }
    else
    {
        selectedMap = 2;
        memcpy(map, map2, sizeof(map2)); /* copiar mapa alternativo do arquivo para o jogo */
        generateHiddenMap30(map, hiddenMap, playerX, playerY, NULL, 0);
    }

    printMap30(hiddenMap, playerX, playerY, traps, trapCount);

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
                trapCheck(playerX, playerY, map, traps, trapCount, trapCheckedMap);
            }
            CLEAR_SCREEN();
            printMap30(hiddenMap, playerX, playerY, traps, trapCount);
            personagem.vida--;
            break;
        }

        /* Movimento e condições */
        if (newX >= 0 && newX < MAP_SIZE && newY >= 0 && newY < MAP_SIZE)
        {
            if (map[newY][newX] == 'X') /* CHEGOU NO BOSS */
            {
                CLEAR_SCREEN();
                printf("\n\nVOCÊ CHEGOU NO FIM. ENFRENTE SEU DESTINO:\n");
                /* boss(); */
            }
            if (map[newY][newX] != WALL_CHAR)
            {
                playerX = newX;
                playerY = newY;
            }
        }

        /* pisou na trap? */
        for (i = 0; i < trapCount; i++)
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
        generateHiddenMap30(map, hiddenMap, playerX, playerY, traps, trapCount);
        printMap30(hiddenMap, playerX, playerY, traps, trapCount);
    }
}
