#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char placa[8];
    char marca[30];
    char cor[20];
}CARRO;

typedef struct _no {
    struct _no *next;
    CARRO carro;
} no;

typedef struct {
    no *ini;
    int N, Nmax;
} est;

void create( est *p );

int insere( est *p, CARRO novo_carro );

void remover( est *p, char placa[] );

int altera( est *p, char placa[], CARRO edit_carro );

int busca( est *p, char placa[] );

int full( est *p);

int empty( est *p );

void show( est *p );

int main() {
    est e;
    CARRO car;
    create(&e);

    strcpy(car.placa, "ABC0000\0");
    strcpy(car.marca, "Golzinho\0");
    strcpy(car.cor, "Vermelho\0");


    insere(&e, car);

    strcpy(car.placa, "DEF0001\0");
    strcpy(car.marca, "Fiat Uno\0");
    strcpy(car.cor, "Verde\0");

    insere(&e, car);
    //
    // remover(&e, "ABC0000");
    if((busca(&e, "ABC0000"))) {
        printf("Sim, %s esta estacionado\n", car.placa);
    }


    show(&e);

    return 0;
}

void create( est *p ) {
    p->ini = NULL;
    p->Nmax = 200;
    p->N = 0;
}

int insere( est *p, CARRO novo_carro ) {
    if( !full(p) ){

        if( empty(p) ) {
            no *novo = (no*)malloc(sizeof(no));
            p->ini = novo;

            strcpy(novo->carro.placa, novo_carro.placa);
            strcpy(novo->carro.marca, novo_carro.marca);
            strcpy(novo->carro.cor, novo_carro.cor);

            p->N++;
            novo->next = NULL;
            return 1;
        }
        no *novo = (no*)malloc(sizeof(no));
        novo->next = p->ini;
        p->ini = novo;

        strcpy(novo->carro.placa, novo_carro.placa);
        strcpy(novo->carro.marca, novo_carro.marca);
        strcpy(novo->carro.cor, novo_carro.cor);

        p->N++;
        return 1;
    }
    return 0;
}

void remover( est *p, char placa[] ) {
    if(!empty(p)) {
        no *node = p->ini;
        no *aux = p->ini->next;
        int first = 1;
        while(node != NULL) {

            if (strcmp(node->carro.placa, placa) == 0) {
                p->N--;
                if( first ) {
                    p->ini = node->next;
                    free(node);
                    return;
                }
                if(node->next == NULL) { // Se no estiver no final
                    aux->next = NULL;
                    free(node);
                    return;
                }
                aux->next = node->next;
                free(node);
                return;
            }

            aux = node;
            node = node->next;
            first = 0;
        }
    }
}

int altera( est *p, char placa[], CARRO edit_carro ) {
    if(!empty(p)) {
        no *node = p->ini;
        while( node != NULL ) {
            if( strcmp(node->carro.placa, placa) == 0 ) {
                strcpy(node->carro.placa, edit_carro.placa);
                strcpy(node->carro.marca, edit_carro.marca);
                strcpy(node->carro.cor, edit_carro.cor);
                return 1;
            }
            node = node->next;
        }
    }
    return 0;

}

int busca( est *p, char placa[] ) {
    if(!empty(p)) {
        no *node = p->ini;
        while(node != NULL) {
            if(strcmp(node->carro.placa, placa) == 0) {
                return 1;
            }
            node = node->next;
        }
    }

    return 0;
}

int full( est *p) {
    return p->N == p->Nmax;
}

int empty( est *p ) {
    return p->ini == NULL;
}

void show( est *p ) {
    if (empty(p)) return;

    no *node = p->ini;

    int i = 0;

    while (i < p->N) {
        printf("Carro:\nPlaca: %s;\nMarca: %s;\nCor: %s\n\n", node->carro.placa, node->carro.marca, node->carro.cor);
        node = node->next;
        i++;
    }
    printf("\n");
}
