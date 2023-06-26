#ifndef MAPWALKING20_H
#define MAPWALKING20_H
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

extern Trap traps[20];

void printMap20(char map[MAP_SIZE20][MAP_SIZE20], int playerX, int playerY, Trap traps[], int trapCount20);

void generateHiddenMap20(char map[MAP_SIZE20][MAP_SIZE20], char hiddenMap[MAP_SIZE20][MAP_SIZE20], int playerX, int playerY, Trap traps[], int trapCount20);

void trapCheck20(int playerX, int playerY, char map[MAP_SIZE20][MAP_SIZE20], Trap traps[], int trapCount20, int trapCheck20edMap[MAP_SIZE20][MAP_SIZE20]);

void mazeGame20();