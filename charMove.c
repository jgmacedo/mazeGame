/* Instruc ̧ ̃oes para compilar:
* gcc -c teste.c -ansi
* gcc -o programa teste.o funcoes_auxiliares.o -ansi
*/
#include <stdio.h>
#include "funcoes_auxiliares.h"
int main()
{
int i;
for (i = 0; i < 10; i++) {
printf("%d\n", le_tecla());
}
return 0;
}