#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void intopost(stack *p, char ex[]) {
    push(p, '(')
    char Y[20];
    strcpy(Y, ex);
    ex[strlen(ex)] = ')';
    for(int i = 0 ; i < strlen(ex), i++) {
        if(ex[i] > 64 || ex[i] < 90) {
            Y[i] = ex[i];
        }
        if(ex[i] == '(') {
            push(p, ex[i]);
        }
    }
}

int main() {
    stack s;
    int ex[20];

    create(&s, 20);

    scanf("\n%20[^\n]", ex);

    intopost(&s, ex);

    printf("Postfix: %s\n", ex);

    // peek(&s);

    return 0;
}
