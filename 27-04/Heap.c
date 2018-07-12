#include "Heap.h"


void inicializar(priority_queue *q, int (*comp)(T,T)) {
    q->n = 0;
    q->comp = comp;
}
void inserir( priority_queue *q, T item ) {
    if(q->n < MAX) {
        q->vetor[q->n] = item;
        fixUp(q, q->n);
        q->n++;
    }
}

void fixUp(Item vetor[], int k) {
    while (k > 0 && vetor[(k-1)/2] < vetor[k]) {
        swap(vetor[k], vetor[(k-1)/2]);
        k = (k-1)/2;
    }
}

void swap(T *A, T *B) {
    T t = A ; *A = *B ; *B = t;
}

void remover( priority_queue *q, T item ) {

}

void tamanho( priority_queue *q ) {

}

void prioritario( priority_queue *q, T item ) {
    if(q->n > 0) {
        *item = q->vetor[0];
    }
}

void
