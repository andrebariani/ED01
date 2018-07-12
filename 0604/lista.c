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

void insereAntes(Iterador* it, T item) {
	if(!acabou(it)){
		Iterador ini = inicio(it->l);
		while(!acabou(&ini)) {
			if(ini.p->prox == it->p) {
				No* novo = (No*)malloc(sizeof(No));
				novo->item = item;
				novo->prox = it->p;
				ini.p->prox = novo;
				it->l->qtd++;
				return;
			}
			proximo(&ini);
		}
	}
}

void removeDepois(Iterador* it, T* item) {
	if(!acabou(it)) {
		No* p = it->p->prox;
		it->p->prox = it->p->prox->prox;
		it->l->qtd--;
		free(p);
	}
}

void remover(Iterador* it, T* item) {
	if(!acabou(it)){
		Iterador ini = inicio(it->l);
		while(!acabou(&ini)) {
			if(ini.p->prox == it->p) {
				No* p = it->p;
				ini.p->prox = it->p->prox;
				it->l->qtd--;
				free(p);
			}
			proximo(&ini);
		}
	}
}

void removeAntes(Iterador* it, T* item) {
	if(!acabou(it)){
		Iterador ini = inicio(it->l);
		while(!acabou(&ini)) {
			if(ini.p->prox->prox == it->p) {
				No* p = ini.p->prox;
				ini.p = it->p;
				it->l->qtd--;
				free(p);
			}
			proximo(&ini);
		}
	}
}

int quantidade(Lista* l) {
	return l->qtd;
}

int vazia(Lista* l) {
	return (l->ini == NULL);
}
//
// int igual(Lista* L1, Lista* L2) {
// 	// ### CLIENT IMPLEMENTATION ###
// 	Iterador it1 = inicio(l1);
// 	Iterador it2 = inicio(l2);
//
// 	while(!acabou(&l1) && !acabou(&l2)) {
// 		elemento(&it1, &e1);
// 		elemento(&it2, &e2);
// 		if(e1 != e2)
// 			return 0;
// 		proximo(&it1);
// 		proximo(&it2);
// 	}
//
// 	if( !acabou(&l1) && !acabou(&l2) )
// 		return 1;
// }
