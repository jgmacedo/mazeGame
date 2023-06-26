#ifndef NOVOPERSONAGEM_H
#define NOVOPERSONAGEM_H
#endif

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

extern struct boneco personagem;

void novoPersonagem();