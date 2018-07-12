#include <stdio.h>
#include <stdlib.h>
#include "fila_list.h"

int main() {

    fila f;
    char c;

    create(&f, 10);

    put(&f, 'J');
    put(&f, 'O');
    put(&f, 'G');
    put(&f, 'O');

    peek(&f);

    get(&f, &c);
    printf("Item get: %c\n", c);
    peek(&f);

    get(&f, &c);
    printf("Item get: %c\n", c);
    peek(&f);


    get(&f, &c);
    printf("Item get: %c\n", c);
    peek(&f);

    return 0;
}
