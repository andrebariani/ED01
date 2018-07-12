#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void conv(stack *p, int num) {
    if(!num) {
        return;
    }
    else{
        push(p, num % 2);
        conv(p, num / 2);
    }
}

int main() {
    stack s;
    int num = 127;

    create(&s, 20);

    conv(&s, num);

    printf("Decimal: %d\n", num);

    peek(&s);

    return 0;
}
