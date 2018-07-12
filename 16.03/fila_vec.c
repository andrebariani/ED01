#include "fila_vec.h"
#include <stdlib.h>
#include <stdio.h>

void create(fila *p, int nmax) {
    p->N = 0;
    p->head = 0;
    p->tail = 0;
    p->Nmax = nmax;
}

int put(fila *p, char item) {
    if(!full(p)) {
        p->N++;
        p->s[p->tail++] = item;
        p->tail = p->tail % p->Nmax;
        return 1;
    }
    return 0;
}

int get(fila *p, char *item) {
    if(!empty(p)) {
        p->N--;
        *item = p->s[p->head++];
        p->head = p->head % p->Nmax;
        return 1;
    }
    return 0;
}

int full(fila *p) {
    return p->Nmax == p->N;
}

int empty(fila *p) {
    return p->N == 0;
}
void peek(fila *p) {
    if(empty(p)) return;
    for(int i = 0 ; i < p->N ; i++){
        printf("%c ", p->s[i]);
    }
    printf("\n");
}
