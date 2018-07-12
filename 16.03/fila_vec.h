#ifndef FILA_VEC_H_
#define FILA_VEC_H_

struct _fila{
    char *s;
    int N, Nmax, head, tail;
};
typedef struct _fila fila;
void create(fila *p, int nmax);

int put(fila *p, char item);

int get(fila *p, char *item);

int full(fila *p);

int empty(fila *p);

void peek(fila *p);

#endif
