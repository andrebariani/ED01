#ifndef ARVORE_H_
#define AARVORE_H_

typedef char T;
typedef const MAX = 3;
// stack

typedef struct _no{
    struct _no *next;
    T s;
} no;

typedef struct {
    no *ini;
    int N, Nmax;
} stack;

// stack methods

void create(stack *p, int nmax);
int push(stack *p, T item);
int pop(stack *p, T *item);
int full(stack *p);
int empty(stack *p);
void peek(stack *p);

// tree

struct node {
    T data[MAX-1];
    int nfilhos;
    int processado = 0;
    struct node *filhos[MAX];
    struct node *pai; // opcional
};

// tree methods

void pre_order( struct node *p );
#endif
// a substitutiva do mario, so com atestado?
// hmmmmm...
// ...
// ...
// nao sei
// mas pergunta
// o mario eh legal
// se conversar e explicar para ele, vai que
// talvez ameacas funcione
// com VIATURAS
// e HELICOPTERO
// e SIRENES
// e LUZES COLORIDAS
// pode ser tbm aqueles TANQUES
// tipo SWAT
