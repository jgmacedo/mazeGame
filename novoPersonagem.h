#ifndef NOVOPERSONAGEM_H
#define NOVOPERSONAGEM_H


#define MAX_HISTORIA 401

struct boneco
{
    int vida;
    int raca;
    int alinhamento;
    int profissao;
    char historiaPrevia[MAX_HISTORIA];
    int porte;
    int forca;
    int destreza;
    int inteligencia;
    int constituicao;
};

struct boneco personagem;

void novoPersonagem();
#endif