#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void jokenpo()
{
    srand(time(NULL));
    int vitoria = 0;
    while (vitoria != 2)
    {
        int jokenpoUsuario;

        int jokenpoAdversario = rand() % 3;
        jokenpoAdversario++;

        printf("Escolha o que deseja jogar: \n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");
        printf("-> ");
        if (scanf("%d", &jokenpoUsuario) != 1)
        {
            printf("Entrada inválida. Tente novamente.\n");
            continue;
        }

        printf("Ele jogou: %d \n", jokenpoAdversario);
        if ((jokenpoUsuario == 1 && jokenpoAdversario == 1) ||
            (jokenpoUsuario == 2 && jokenpoAdversario == 2) ||
            (jokenpoUsuario == 3 && jokenpoAdversario == 3))
        {
            printf("* Vocês empataram! Joguem Novamente. *\n\n");
            continue;
        }
        else if ((jokenpoUsuario == 1 && jokenpoAdversario == 2) ||
                 (jokenpoUsuario == 2 && jokenpoAdversario == 3) ||
                 (jokenpoUsuario == 3 && jokenpoAdversario == 1))
        {
            printf("Não foi dessa vez... Você perdeu!\n");
            personagem.vida -= 1;
            printf("Você está com %d pontos de vida\n\n", personagem.vida);
            if (personagem.vida <= 0)
            {
                printf("Game Over");
                exit(0);
            }
        }
        else if (jokenpoUsuario != 1 && jokenpoUsuario != 2 && jokenpoUsuario != 3)
        {
            printf("\n* Opção Inválida! Tente Novamente *\n");
            continue;
        }
        else
        {
            printf("Você ganhou!\n");
            vitoria++;
            continue;
        }
        continue;
    }
}

void charadas()
{

    int i = 0;
    srand(time(NULL));
    int acerto = 0;
    int respostaCharada = 0;
    int charadaRespondida[10] = {0}; /* Inicializa o array charadaRespondida com 0 */

    while (acerto != 3)
    {
        int charadaSorteada;
        charadaSorteada = rand() % 11;
        charadaSorteada++;

        /* Verifica se a charadaSorteada já foi respondida */
        int repetido = 0;
        int j;
        for (j = 0; j < i; j++)
        {
            if (charadaRespondida[j] == charadaSorteada)
            {
                repetido = 1;
                break;
            }
        }

        if (repetido == 1)
        {
            continue; /* Sorteia novamente se o número já tiver sido respondido */
        }

        charadaRespondida[i] = charadaSorteada;
        i++;

        if (charadaSorteada == 1)
        {

            printf("O que é o que é? Dá muitas voltas e não sai do lugar.\n");
            printf("1. Ventilador\n");
            printf("2. Parafuso\n");
            printf("3. Relógio\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 3)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 2)
        {
            printf("O que é o que é? Não se come, mas é bom para se comer.\n");
            printf("1. Talher\n");
            printf("2. Receita\n");
            printf("3. Tempero\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 1)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 3)
        {
            printf("O que é, o que é? Nunca volta, embora nunca tenha ido.\n");
            printf("1. O Futuro\n");
            printf("2. O Passado\n");
            printf("3. O Presente\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 2)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 4)
        {
            printf("O que é, o que é? Fica no início da rua, no fim do mar e no meio da cara.\n");
            printf("1. Sinal de trânsito\n");
            printf("2. Barco\n");
            printf("3. Letra 'r'\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 3)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 5)
        {
            printf("O que é, o que é? Pode passar diante do sol sem fazer sombra.\n");
            printf("1. Raio\n");
            printf("2. Vento\n");
            printf("3. Luz\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 2)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 6)
        {
            printf("O que é, o que é? Quanto maior menos se vê.\n");
            printf("1. Escuridão\n");
            printf("2. Tempo\n");
            printf("3. Mistério\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 1)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 7)
        {
            printf("O que é que é? Tem que ser lambido para enfiar no buraco mais facilmente?\n");
            printf("1. Envelope\n");
            printf("2. Linha de Costura\n");
            printf("3. Selo\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 2)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 8)
        {
            printf("O que é, o que é: Quanto mais se tira, mais se aumenta?\n");
            printf("1. Silencio\n");
            printf("2. Divida\n");
            printf("3. Buraco\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 3)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 9)
        {
            printf(" O que é, o que é: Atravessa o rio, mas nunca se molha?\n");
            printf("1. Reflexo\n");
            printf("2. Ponte\n");
            printf("3. Barco\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 2)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }
        if (charadaSorteada == 10)
        {
            printf("O que é, o que é: Quando a gente fica em pé, ele fica deitado, e quando a gente deita, ele fica em pé?\n");
            printf("1. Sombra\n");
            printf("2. Espelho\n");
            printf("3. Os pés\n");
            printf("-> ");
            scanf("%d", &respostaCharada);
            if (respostaCharada == 3)
            {
                printf("Parabéns! Você Acertou.\n\n");
                acerto++;
            }
            else
            {
                printf("Hmm que pena, você errou! Isso te causou menos 1 ponto de vida.");
                personagem.vida -= 1;
                printf("Você está com %d pontos de vida\n\n", personagem.vida);
                if (personagem.vida <= 0)
                {
                    printf("Game Over\n");
                    exit(0);
                }
            }
        }

    } /* fecha chaves do while que faz o loop para as charadas */
}

void boss()
{
    printf("\nFinalmente, você me encontrou, meu jovem...\n");
    printf("\nEsperei todo esse tempo por você... Mas finalmente chegou a hora da nossa batalha! Eu te desafio a me vencer no jogo de Pedra, Papel e Tesoura, se você realmente for bom. Não perco há 112 anos.\n");
    jokenpo();

    system("clear");

    printf("Pensou que a disputa tinha terminado? Muahahah!\n");
    printf("Percebeu que não seria tão simples assim, não é mesmo? Agora, desafio você a resolver três das charadas mais difíceis! Desejo-lhe boa sorte.\n");
    charadas();

    system("clear");
    printf("Após inúmeras provações, perigos superados e enigmas desvendados, você emerge vitorioso do intricado labirinto de Eldoria. Cada passo dado e cada desafio enfrentado serviram como testes de coragem, inteligência e perseverança.\n");
    printf("Ao alcançar a saída, uma luz brilhante ilumina seu caminho, dissipando as sombras do labirinto. As portas se abrem, revelando um mundo novo e radiante. As vozes ancestrais ecoam em seus ouvidos, reconhecendo você como aquele que restaurou o equilíbrio e desvendou os segredos há muito perdidos.\n");
    printf("Agora, a jornada épica chega ao seu fim, mas sua lenda transcenderá as fronteiras de FAVELA DOS PITS\n");
    printf("Você se tornou aquele que triunfou sobre o labirinto enigmático e provou ser digno do título de campeão.\n");
    printf("Parabéns por completar essa jornada extraordinária! Que sua lenda permaneça viva e brilhante por toda a eternidade!\n");
    printf("\nFim do Jogo.\n");
    exit(0);
}