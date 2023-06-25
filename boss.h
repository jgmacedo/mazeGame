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

            printf("O que é, o que é? Quem faz, não usa. Quem usa, não vê. Quem vê, não quer usar.\n");
            printf("1. Bengala\n");
            printf("2. Óculos de Sol\n");
            printf("3. Caixão\n");
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
            printf("O que é que todos têm, alguns perdem, mas ninguém pode dar?\n");
            printf("1. Passado\n");
            printf("2. Sombra\n");
            printf("3. A vida\n");
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
            printf("O que é que sobe e desce sem se mover?\n");
            printf("1. O Sol\n");
            printf("2. Temperatura\n");
            printf("3. Elevador\n");
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
            printf("O que é que todos usam, mas ninguém vê?\n");
            printf("1. Óculos\n");
            printf("2. O nome\n");
            printf("3. O cérebro\n");
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
            printf("Diga o que sou e eu desapareço. O que sou eu?\n");
            printf("1. Segredo\n");
            printf("2. Silêncio\n");
            printf("3. Eco\n");
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
            printf("O que é, o que é? Fica cheio durante o dia e vazio durante a noite.\n");
            printf("1. O sapato\n");
            printf("2. A rua\n");
            printf("3. A escola\n");
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
            printf(" O que é, o que é? Vários pontinhos amarelos na parede.\n");
            printf("1. Reflexo\n");
            printf("2. Fandangos Alpinistas\n");
            printf("3. Sujeira\n");
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
            printf("O que é, o que é? Tem no meio do ovo.\n");
            printf("1. Gema\n");
            printf("2. Clara\n");
            printf("3. A letra 'V'\n");
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
            printf("Eu nunca fui, mas sempre serei. Ninguém nunca me viu, e nunca verão. Ainda assim, sou a esperança de todos. Quem sou eu?\n");
            printf("1. Sonhos\n");
            printf("2. Futuro\n");
            printf("3. Eternidade\n");
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
            printf("O que é o que é? Voa sem ter asas e chora sem ter olhos.\n");
            printf("1. O vento\n");
            printf("2. O pensamento\n");
            printf("3. A Nuvem\n");
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
}