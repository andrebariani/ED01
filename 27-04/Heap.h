#ifndef HEAP_H_
#define HEAP_H_

#define MAX 100

typedef struct {
    int idade;
    int RA;
} T;

typedef struct {
    int n;
    T vetor[MAX];
    int (*comp)(T,T);
} priority_queue;

void inicializar( priority_queue *q, int (*comp)(T,T) );
void inserir( priority_queue *q, T item );
void remover( priority_queue *q, T* item );
void tamanho( priority_queue *q );
void prioritario( priority_queue *q, T* item );
void swap(T *A, T *B);
void fixUp(Item vetor[], int k);
void imprimir( priority_queue *q );

#endif
