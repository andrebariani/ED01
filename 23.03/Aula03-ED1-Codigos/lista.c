#include <stdlib.h>
#include "lista.h"


void inicializa(Lista *l) {
	l->ini = NULL;
	l->qtd = 0;
}

void insereInicio(Lista *l, T item) {
	No* p = (No*)malloc(sizeof(No));
	p->item = item;
	p->prox = l->ini;
	l->ini = p;
	l->qtd++;	
}

void removeInicio(Lista *l, T* item) {
	if(l->ini != NULL) {
		No* p = l->ini;
		l->ini = l->ini->prox;
		*item = p->item;
		free(p);
	}	
}

Iterador inicio(Lista *l) {
	Iterador it;
	it.p = l->ini;
	it.l = l;
	return it;
}

void elemento(Iterador* it, T* item) {
	if(!acabou(it))
		*item = it->p->item;
}

void proximo(Iterador* it) {
	if( !acabou(it) ) {
		it->p = it->p->prox;
	}
}

int acabou(Iterador *it) {
	return it->p == NULL;
}

Iterador buscaPrimeiro(Lista* l, T item) {
	Iterador it = inicio(l);
	while( !acabou(&it) ) {
		if( it.p->item == item )
			return it;
		proximo(&it);
	}
	return it;
}

Iterador buscaProximo(Iterador* it, T item) {
	while( !acabou(it) ) {
		if( it->p->item == item )
			return *it;
		proximo(it);
	}
	return *it;
}

void insereDepois(Iterador* it, T item) {
	if(!acabou(it)) {
		No* novo = (No*)malloc(sizeof(No));
		novo->item = item;
		novo->prox = it->p->prox;
		it->p->prox = novo;
		it->l->qtd++;
	}
}

int quantidade(Lista* l) {
	return l->qtd;
}

void insereAntes(Iterador* it, T item) {
	if(!acabou(it)) {
		
	}
}

