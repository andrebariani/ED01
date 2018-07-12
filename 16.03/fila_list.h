#ifndef FILA_LIST_H_
#define FILA_LIST_H_

typedef struct _no {
    struct _no *next;
    char s;
} no;

typedef struct {
    no *ini;
    int Nmax;
    int N;
} fila;

void create(fila *p, int nmax);

int put(fila *p, char item);

int get(fila *p, char *item);

int full(fila *p);

int empty(fila *p);

void peek(fila *p);

#endif
