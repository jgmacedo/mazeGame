#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "novoPersonagem.h"

void novoPersonagem()
{
    /* inicializaçao do personagem */
    personagem.vida = 20;
    personagem.raca = 0;
    personagem.alinhamento = 0;
    personagem.profissao = 0;
    personagem.porte = 0;
    personagem.forca = 0;
    personagem.destreza = 0;
    personagem.constituicao = 0;
    personagem.inteligencia = 0;
    int pontosAtributo = 10;
    int totalAtributos = 0;

    /* RAÇA DO PERSONAGEM:*/
    while (personagem.raca != 1 && personagem.raca != 2 && personagem.raca != 3)
    {
        printf("\nQual a sua raça?\n");
        printf("1. Humano\n");
        printf("2. Anão\n");
        printf("3. Elfo\n");
        printf("-> ");
        scanf("%d", &personagem.raca);
        printf(": ");
        switch (personagem.raca)
        {
        case 1:
            personagem.raca = 1;
            printf("Entendido, você é um Humano!\n");
            break;
        case 2:
            personagem.raca = 2;
            printf("Entendido, você é um Anão!\n");
            break;
        case 3:
            personagem.raca = 3;
            printf("Entendido, você é um Elfo!\n");
            break;
        /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
        default:
            system("clear");
            printf("\n* Opção Inválida! Tente Novamente *\n\n");
            continue;
        }
    }

    /* ALINHAMENTO DO PERSONAGEM: */
    while (personagem.alinhamento != 1 && personagem.alinhamento != 2 && personagem.alinhamento != 3)
    {
        printf("\nAgora escolha seu lado da força!\n");
        printf("1. Mal\n");
        printf("2. Neutro\n");
        printf("3. Bom\n");
        printf("-> ");
        scanf("%d", &personagem.alinhamento);
        printf(": ");
        switch (personagem.alinhamento)
        {
        case 1:
            personagem.alinhamento = 1;
            printf("Uuui, então parece que você é um vilão... Decisão tomada!\n");
            break;
        case 2:
            personagem.alinhamento = 2;
            printf("Compreendido, você é tranquilo então!\n");
            break;
        case 3:
            personagem.alinhamento = 3;
            printf("Muito bom bonzinho, vá salvar o mundo herói...!\n");
            break;
        /* fazer usuario voltar caso insira alguma das opcoes diferentes */
        default:
            printf("\n* Opção Inválida! Tente Novamente *\n");
            continue;
        }
    }

    /* PROFISSAO DO PERSONAGEM:
    if e else para fazer a restricao se caso o personagem.alinhamento do personagem
    for Bom, ele nao podera escolher a classe Ladino. */
    if (personagem.alinhamento != 3)
    {
        while (personagem.profissao != 1 && personagem.profissao != 2 && personagem.profissao != 3)
        {
            printf("\nQual sua profissão?\n");
            printf("1. Guerreiro\n");
            printf("2. Mago\n");
            printf("3. Ladino\n");
            printf("-> ");
            scanf("%d", &personagem.profissao);
            printf(": ");
            switch (personagem.profissao)
            {
            case 1:
                personagem.profissao = 1;
                printf("Um verdadeiro guerreiro? Fantástico! Você será uma adição poderosa para nossas batalhas!\n");
                break;
            case 2:
                personagem.profissao = 2;
                printf("Uau um mago? Use seus feitiços sem restrições!\n");
                break;
            case 3:
                personagem.profissao = 3;
                printf("Já entendi malandrinho, ladino.\n");
                break;
            /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
            default:
                printf("\n* Opção Inválida! Tente Novamente *\n");
                continue;
            }
        }
    }
    else
    {
        while (personagem.profissao != 1 && personagem.profissao != 2)
        {
            printf("\nQual sua profissão?\n");
            printf("1. Guerreiro\n");
            printf("2. Mago\n");
            printf("-> ");
            scanf("%d", &personagem.profissao);
            printf(": ");
            switch (personagem.profissao)
            {
            case 1:
                personagem.profissao = 1;
                printf("Um verdadeiro guerreiro? Fantástico! Você será uma adição poderosa para nossas batalhas!\n");
                break;
            case 2:
                personagem.profissao = 2;
                printf("Uau um mago? Use seus feitiços sem restrições!\n");
                break;
            /* fazer usuario voltar caso insira alguma das opcoes diferentes */
            default:
                printf("\n* Opção Inválida! Tente Novamente *\n");
                continue;
            }
        }
    }

    /* PORTE DO PERSONAGEM:
             if e else para fazer a restricao caso a raca do personagem
            for Anao, ele nao podera escolher o porte Grande */
    if (personagem.raca != 2)
    {
        while (personagem.porte != 1 && personagem.porte != 2 && personagem.porte != 3)
        {
            printf("\nQual sua altura?\n");
            printf("1. Grande, de 2m \n");
            printf("2. Médio, de 1.70m\n");
            printf("3. Pequeno, de 1.50m\n");
            printf("-> ");
            scanf("%d", &personagem.porte);
            printf(": ");
            switch (personagem.porte)
            {
            case 1:
                personagem.porte = 1;
                printf("Impressionante para amedrontar seus inimigos! Uma escolha excelente!\n");
                break;
            case 2:
                personagem.porte = 2;
                printf("Nem tão alto, nem tão baixo... Ótima escolha!\n");
                break;
            case 3:
                personagem.porte = 3;
                printf("Tamanho não é documento não é mesmo!\n");
                break;
            /* fazer usuario voltar caso insira alguma das opcoes diferentes*/
            default:
                printf("\n* Opção Inválida! Tente Novamente *\n");
                continue;
            }
        }
    }
    else
    {
        while (personagem.porte != 2 && personagem.porte != 3)
        {
            printf("\nQual sua altura?\n");
            printf("2. Médio, de 1.45m\n");
            printf("3. Pequeno, de 1.20m\n");
            printf("-> ");
            scanf("%d", &personagem.porte);
            printf(": ");
            switch (personagem.porte)
            {
            case 2:
                personagem.porte = 2;
                printf("Nem tão alto, nem tão baixo... Ótima escolha!\n");
                break;
            case 3:
                personagem.porte = 3;
                printf("Tamanho não é documento não é mesmo!\n");
                break;
            /* fazer usuario voltar caso insira alguma das opcoes */
            default:
                printf("\n* Opção Inválida! Tente Novamente *\n");
                continue;
            }
        }
    }
    printf("\nAgora para finalizar, conte-nos uma história prévia de como "
           "seu personagem viveu até esse momento. [até 400 caracteres] : ");
    scanf(" %[^\n]", personagem.historiaPrevia);

    printf("\nMuito Bem! Agora vamos definir seus atributos.\n");
    printf("- Seus atributos somados têm que dar no máximo 10 pontos\n");
    printf("- Obs: Cada atributo deve conter [de 1 até 5]\n\n");

    while ((personagem.forca > 5) || (personagem.forca < 1))
    {
        printf("Força: [1 ~ 5]\n");
        scanf(" %d", &personagem.forca);
        if ((personagem.forca > 5) || (personagem.forca < 1))
        {
            printf("Valor inválido. Tente Novamente\n");
            continue;
        }
        else
        {
            totalAtributos += personagem.forca;
            pontosAtributo -= personagem.forca;
            printf("\n* Voce ja gastou %d atributos e lhe restam apenas %d pontos *\n", totalAtributos, pontosAtributo);
            break;
        }
    }

    while ((personagem.destreza > 5) || (personagem.destreza < 1) || ((personagem.forca + personagem.destreza) > 8))
    {
        printf("Destreza: [1 ~ 5]\n");
        scanf(" %d", &personagem.destreza);
        if ((personagem.destreza > 5) || (personagem.destreza < 1))
        {
            printf("Valor inválido. Tente Novamente\n");
            continue;
        }
        else if ((personagem.forca + personagem.destreza) > 8)
        {
            printf("\nPontos insuficientes, lembre-se que todos precisam conter no minimo 1!\n");
            continue;
        }
        else
        {
            totalAtributos += personagem.destreza;
            pontosAtributo -= personagem.destreza;
            printf("\n* Voce ja gastou %d atributos e lhe restam apenas %d pontos *\n", totalAtributos, pontosAtributo);
            break;
        }
    }

    while ((personagem.inteligencia > 5) || (personagem.inteligencia < 1) || ((personagem.forca + personagem.destreza + personagem.inteligencia) > 9))
    {
        printf("Inteligencia: [1 ~ 5]\n");
        scanf(" %d", &personagem.inteligencia);
        if ((personagem.inteligencia > 5) || (personagem.inteligencia < 1))
        {
            printf("Valor inválido. Tente Novamente\n");
            continue;
        }
        else if ((personagem.forca + personagem.destreza + personagem.inteligencia) > 9)
        {
            printf("\nPontos insuficientes, lembre-se que todos precisam conter no minimo 1!\n");
            continue;
        }
        else
        {
            totalAtributos += personagem.inteligencia;
            pontosAtributo -= personagem.inteligencia;
            printf("\n* Voce ja gastou %d atributos e lhe restam apenas %d pontos *\n", totalAtributos, pontosAtributo);
            break;
        }
    }
    while ((personagem.constituicao > 5) || (personagem.constituicao < 1) || ((personagem.forca + personagem.destreza + personagem.inteligencia + personagem.constituicao) > 10))
    {
        printf("Constituicao: [1 ~ 5]\n");
        scanf(" %d", &personagem.constituicao);
        if ((personagem.constituicao > 5) || (personagem.constituicao < 1))
        {
            printf("Valor inválido. Tente Novamente\n");
            continue;
        }
        else if ((personagem.forca + personagem.destreza + personagem.inteligencia + personagem.constituicao) > 10)
        {
            printf("\nPontos insuficientes, lembre-se que todos precisam conter no minimo 1!\n");
            continue;
        }
        else
        {
            totalAtributos += personagem.constituicao;
            pontosAtributo -= personagem.constituicao;
            break;
        }
    }

    system("clear");
    if (personagem.raca == 3)
    {
        personagem.destreza++;
        personagem.constituicao--;
        printf("Por você ser Elfo: Destreza +1, Constituição -1\n");
    }
    if (personagem.raca == 2)
    {
        personagem.forca++;
        personagem.destreza--;
        printf("Por você ser Anão: Força +1, Destreza -1\n");
    }
    if (personagem.profissao == 2)
    {
        personagem.inteligencia++;
        personagem.forca -= 2;
        printf("Por você ser Mago: Inteligência +1, Força -2\n");
    }
    if (personagem.profissao == 3)
    {
        personagem.destreza++;
        personagem.forca--;
        personagem.inteligencia--;
        printf("Por você ser Ladino: Destreza +1, Força -1, Inteligência -1\n");
    }

    if (personagem.constituicao <= 0)
    {
        personagem.vida = 10;
    }
    else
    {
        personagem.vida = personagem.constituicao * 20;
    }
    printf("\nExcelente, seu personagem foi criado:\n");
    printf("FORÇA: %d\n", personagem.forca);
    printf("DESTREZA: %d\n", personagem.destreza);
    printf("ITELIGÊNCIA: %d\n", personagem.inteligencia);
    printf("CONSTITUIÇÃO: %d\n", personagem.constituicao);

    printf("\nVocê tem %d pontos de vida para seguir sua jornada! Boa Sorte...\n\n", personagem.vida);

    return personagem;
}