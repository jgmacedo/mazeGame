#ifndef MAPWALKING50_H
#define MAPWALKING50_H


#define MAP_SIZE50 50
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
} Trap50;

extern Trap50 traps50[35];

void printMap50(char map[MAP_SIZE50][MAP_SIZE50], int playerX, int playerY, Trap50 traps50[], int trapCount);

void generateHiddenMap50(char map[MAP_SIZE50][MAP_SIZE50], char hiddenMap[MAP_SIZE50][MAP_SIZE50], int playerX, int playerY, Trap50 traps50[], int trapCount);

void trapCheck50(int playerX, int playerY, char map[MAP_SIZE50][MAP_SIZE50], Trap50 traps50[], int trapCount, int trapCheckedMap[MAP_SIZE50][MAP_SIZE50]);

void mazeGame50();
#endif