#include <stdlib.h>

#include "list.h"

void create( list* l ) {
    l->ini = NULL;
    l->qtd = 0;
}

void insertBegin(list* l, char item) {
    node* p = (node*)malloc(sizeof(node));
    p->item = item;
    p->prox = l->ini;
    l->ini = p;
    l->qtd++;
}


void removeBegin(list* l, char* item) {
    if(l->ini != NULL) {
        node* p = l->ini;
        l->ini = l->ini->prox;
        *item = p->item;
        free(p);
    }
}


Iterador inicio(list *l) {
    Iterador it;
    it.p = l->ini;
    it.l = l;
    return it;
}

void element(Iterador *it, char *item) {
    if(!over(it))
        *item = it->p->item;
}

void proximo(Iterador *it) {
    if(!over(it))
        *item = it->p->prox;
}


int over(Iterador *it) {
    return it->p == NULL;
}

Iterador searchFirst(list *l, char item) {
    Iterador it = inicio(l);
    while( !over(&it) ) {
        if(it->p->item == item)
            return it;
        proximo(&it);
    }
    return it;
}

Iterador searchNext(list *l, char item) {
    Iterador it = inicio(l);
    while( !over(&it) ) {
        if(it->p->item == item)
            return it;
        proximo(&it);
    }
    return it;
}

void insereDepois(Iterador *it, char item) {
    if(!over(it)) {
        node* novo = (node*)malloc(sizeof(node));
    }
}
