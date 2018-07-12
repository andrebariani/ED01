#include "stack_vec.h"
#include <stdlib.h>
#include <stdio.h>

int create(stack *p, int nmax) {
    p->s = (char*)malloc(sizeof(char)*nmax);
    p->N = 0;
    p->Nmax = nmax;
    if(p->s) return 1;
    else return 0;
}

int push(stack *p, char item) {
    if(p->N < p->Nmax) {
        p->s[p->N++] = item;
        return 1;
    }
    return 0;
}

int pop(stack *p, char *item) {
    if(p->N > 0) {
        *item = p->s[--p->N];
        return 1;
    }
    return 0;
}

int full(stack *p) {
    return p->N == p->Nmax;
}

int empty(stack *p) {
    return p->N == 0;
}

void peek(stack *p) {
    if (empty(p)) return;

    for(int i = 0 ; i < p->N ; i++) {
        printf("%c ", p->s[i]);
    }
    printf("\n");
}
