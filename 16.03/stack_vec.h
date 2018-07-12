#ifndef STACK_VEC_H_
#define STACK_VEC_H_

struct _stack{
    char *s;
    int N, Nmax;
};
typedef struct _stack stack;

int create(stack *p, int nmax);

int push(stack *p, char item);

int pop(stack *p, char *item);

int full(stack *p);

int empty(stack *p);

void peek(stack *p);

#endif
