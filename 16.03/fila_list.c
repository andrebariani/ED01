#include <stdio.h>
#include <stdlib.h>
#include "fila_list.h"

void create(fila *p, int nmax) {
    p->ini = NULL;
    p->N = 0;
    p->Nmax = nmax;
}

int put(fila *p, char item) {
    if(!full(p)) {
        no *novo = (no*)malloc(sizeof(no));
        if(empty(p)) {
            p->ini = novo;
            novo->s = item;
            p->N++;
            novo->next = NULL;
            return 1;
        }
        no *f = p->ini;
        while(f != NULL) {
            if(f->next == NULL) {
                f->next = novo;
                novo->s = item;
                novo->next = NULL;
                p->N++;
                return 1;
            }
            f = f->next;
        }

    }
    return 0;
}

int get(fila *p, char *item) {
    if(!empty(p)) {
        p->N--;
        no *out = p->ini;
        p->ini = p->ini->next;
        *item = out->s;
        free(out);
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
    int i = 0;
    no *node = p->ini;
    while(i<p->N) {
        printf("%c ", node->s);
        node = node->next;
        i++;
    }
    printf("\n");
}
