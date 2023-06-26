#ifndef MAPWALKING30_H
#define MAPWALKING30_H
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

extern Trap30 traps30[25];

void printMap30(char map30[MAP_SIZE30][MAP_SIZE30], int playerX, int playerY, Trap30 traps30[], int trapCount30);

void generateHiddenMap30(char map30[MAP_SIZE30][MAP_SIZE30], char hiddenMap[MAP_SIZE30][MAP_SIZE30], int playerX, int playerY, Trap30 traps30[], int trapCount30);

void trapCheck30(int playerX, int playerY, char map30[MAP_SIZE30][MAP_SIZE30], Trap30 traps30[], int trapCount30, int trapCheck30edMap30[MAP_SIZE30][MAP_SIZE30]);

void mazeGame30();