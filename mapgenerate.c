#include <stdio.h>

int main() {
    int i, j;
    for (i = 0; i < 50; i++) {
        printf("{");
        for (j = 0; j < 50; j++) {
            if (i > 0 && i < 49 && j > 0 && j < 49) {
                printf("' '");
            } else {
                printf("'#'");
            }
            if (j != 49) {
                printf(", ");
            }
        }
        printf("},\n");
    }
    return 0;
}