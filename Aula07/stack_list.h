#ifndef STACK_LIST_H_
#define STACK_LIST_H_

typedef struct _no{
    struct _no *next;
    char s;
} no;

typedef struct {
    no *ini;
    int N, Nmax;
} stack;

void create(stack *p, int nmax);

int push(stack *p, char item);

int pop(stack *p, char *item);

int full(stack *p);

int empty(stack *p);

void peek(stack *p);

#endif
