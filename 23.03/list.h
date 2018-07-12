#ifndef LIST_H_
#define LIST_H_

typedef struct _no {
    char item;
    struct _no* prox;
} node;


typedef struct list {
    int qtd;
    node* ini;
}list;

typedef struct iterador {
    node* p;
    list *l;
} Iterador;

void create(list* p);

void insertBegin(list *p, char item);

void removeBegin(list *l, char *item);

Iterador inicio(list *l);

void element(Iterador *it, char *item);

void proximo(Iterador *it);

int over(Iterador *it);

Iterador searchFirst(list *l, char item);

Iterador searchNext(list *l, char item);

void insereDepois(Iterador *it, char item);

void insereAntes(Iterador *it, char item);
#endif
