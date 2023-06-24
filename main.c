#include <stdio.h>
#include <string.h>
#include "menu.h"
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

int main()
{

    menu();

    return 0;
}