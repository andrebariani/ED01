#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    list letra;

    create(&letra);

    insertBegin(&letra, 'J');

    char c;

    removeBegin(&letra, &c);

    printf("%c\n", c );

    return 0;
}
