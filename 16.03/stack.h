#ifndef STACK_LINK_H_
#define STACK_LINK_H_

typedef struct _stack{
    char *s;
    int N, Nmax;
} stack;

int create(stack *p, int nmax);

int push(stack *p, char item);

int pop(stack *p, char *item);

int full(stack *p);

int empty(stack *p);

void peek(stack *p);

#endif
