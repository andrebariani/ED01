#ifndef STACK_VEC_H_
#define STACK_VEC_H_

typedef char T;

struct _stack{
    T *s;
    int N, Nmax;
};
typedef struct _stack stack;

int create(stack *p, int nmax);

int push(stack *p, T item);

int pop(stack *p, T *item);

int full(stack *p);

int empty(stack *p);

void peek(stack *p);

#endif
