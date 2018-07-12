#ifndef HEAP_H
#define HEAP_H

typedef char T;


struct node {
	T data;
	struct node *esq, *dir;
	struct node *pai; // opcional
};

void inicializa(Lista* l);
void destroi(Lista* l);
void insereInicio(Lista* l, T item);
void insereFim(Lista* l, T item);
void removeInicio(Lista* l, T* item);
void removeFim(Lista* l, T* item);
Iterador inicio(Lista* l);
Iterador fim(Lista* l);
void elemento(Iterador* it, T* item);
void proximo(Iterador* it);
void anterior(Iterador* it);
int acabou(Iterador *it);
Iterador buscaPrimeiro(Lista* l, T item);
Iterador buscaUltimo(Lista* l, T item);
Iterador buscaProximo(Iterador* it, T item);
Iterador buscaAnterior(Iterador* it, T item);
void insereDepois(Iterador* it, T item);
void insereAntes(Iterador* it, T item);
void removeDepois(Iterador* it, T* item);
void remover(Iterador* it, T* item);
void removeAntes(Iterador* it, T* item);
int quantidade(Lista* l);
int vazia(Lista* l);



#endif
