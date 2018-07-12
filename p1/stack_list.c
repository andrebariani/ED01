#include "stack_list.h"
#include <stdlib.h>
#include <stdio.h>

void create(stack *p, int nmax) {
    p->ini = NULL;
    p->N = 0;
    p->Nmax = nmax;
}

int push(stack *p, T item) {
    if( !full(p) ){

        if( empty(p) ) {
            no *novo = (no*)malloc(sizeof(no));
            p->ini = novo;
            novo->s = item;
            p->N++;
            novo->next = NULL;
            return 1;
        }
        no *novo = (no*)malloc(sizeof(no));
        novo->next = p->ini;
        p->ini = novo;
        novo->s = item;
        p->N++;
        return 1;
    }
    return 0;
}

int pop(stack *p, T *item) {
    if(p->N > 0) {
        no *topo = p->ini;
        *item = topo->s;
        p->ini = topo->next;
        free(topo);
        p->N--;
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

    no *node = p->ini;

    int i = 0;

    while (i < p->N) {
        printf("%c ", node->s);
        node = node->next;
        i++;
    }
    printf("\n");
 }
