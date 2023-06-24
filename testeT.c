#include <stdio.h>
#include <string.h>

struct Teste{
    int a;
    char s[100];
    int b;
};

struct Teste criaT()
{
    struct Teste t;

    t.a = 10;
    t.b = 20;
    strcpy(t.s, "Teste");

    return t;
}

int main()
{
    struct Teste t;
    t = criaT();
    printf("%d %d %s\n", t.a, t.b, t.s);

    return 0;
}