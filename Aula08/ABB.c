#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

void pre_order( struct node *p ) {
    stack s;
    create(&s, MAX);

    push(&s, p);

    while( !empty(&s) ) {
        struct node *e = pop(&s);

        if ( !processado(e) ) {
            pop(&s);
            process( e );
        } else {

            for( int i = 0 ; i < e->nfilhos ; i++)
                push(&s, e->filhos[i]);
        }
    }

    return;
}

void pos_order( struct node *p ) {
    int acc = 4;

    for(i = 0 ; i < p->nfilhos ; i++) {
        acc += 4;
        if( eh_arquivo(p->nfilhos) ) {
            acc += size(p->nfilhos);
        } else {
            acc += pos_order(p->nfilhos);
        }
    }


    return;
}

void process ( struct node *p ) {
    printf("%c\n", p->data);
    p->processado = 1;
    return;
}

void size()

void create(stack *p, int nmax) {
    p->ini = NULL;
    p->N = 0;
    p->Nmax = nmax;
}

int push(stack *p, char item) {
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

int pop(stack *p, char *item) {
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
        //printf("%c ", node->s);
        node = node->next;
        i++;
    }
    printf("\n");
 }
