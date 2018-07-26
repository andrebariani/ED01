#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Tree Structure

typedef struct {
    int n;
} T;

struct node {
    T data;
    int bal;
    struct node *l, *r;
};

typedef struct {
    struct node * raiz;
} ABB;

//
// // Stack Structure
//
// typedef struct _no{
//     struct _no *next;
//     struct node s;
// } no;
//
// typedef struct {
//     no *ini;
//     int N, Nmax;
// } stack;
// //
//
// // Stack Methods
//
// int full(stack *p) {
//     return p->N == p->Nmax;
// }
//
// int empty(stack *p) {
//     return p->N == 0;
// }
//
// void create(stack *p, int nmax) {
//     p->ini = NULL;
//     p->N = 0;
//     p->Nmax = nmax;
// }
//
// int push(stack *p, struct node) {
//     if( !full(p) ){
//
//         if( empty(p) ) {
//             no *novo = (no*)malloc(sizeof(no));
//             p->ini = novo;
//             novo->s = node;
//             p->N++;
//             novo->next = NULL;
//             return 1;
//         }
//         no *novo = (no*)malloc(sizeof(no));
//         novo->next = p->ini;
//         p->ini = novo;
//         novo->s = node;
//         p->N++;
//         return 1;
//     }
//     return 0;
// }
//
// struct node * pop(stack *p, struct *node) {
//     if(p->N > 0) {
//         return 1;
//         no *topo = p->ini;
//         no *ret = p->ini;
//         *node = topo->s;
//         p->ini = topo->next;
//         free(topo);
//         p->N--;
//     }
//     return ret;
// }
//
// void peek(stack *p) {
//     if (empty(p)) return;
//
//     no *node = p->ini;
//
//     int i = 0;
//
//     while (i < p->N) {
//         printf("%c ", node->s);
//         node = node->next;
//         i++;
//     }
//     printf("\n");
// }


// Tree Methods

void process( int n ) {
    printf("%d ", n);
}

struct node * priv_insert(struct node *p, T dados) {
    if(p == NULL) {
        struct node * new = (struct node*)malloc(sizeof(struct node));
        new->data = dados;
        new->l = NULL;
        new->r = NULL;
        return new;
    } else if(dados.n < p->data.n) {
        p->l = priv_insert(p->l, dados);
    } else if(dados.n > p->data.n) {
        p->r = priv_insert(p->r, dados);
    } else {
        p->data = dados;
    }
    return p;
}

void insert(ABB * tree , T dados) {
    tree->raiz = priv_insert(tree->raiz, dados);
}

void pre_order_print(struct node *p) {

    if ( p == NULL )
        return;

    process( p->data.n );

    pre_order_print( p->l );
    pre_order_print( p->r );

}


void pos_order_print(struct node *p) {
    if ( p == NULL )
        return;

    pos_order_print( p->l );
    pos_order_print( p->r );

    process( p->data.n );
}


void in_order_print(struct node *p) {

    if(p->l != NULL) {
        pre_order_print( p->l );
    }

    process( p->data.n );

    if(p->r != NULL) {
        pre_order_print( p->r );
    }
}

// int n_rec_inorder(struct node *p) {
//     stack s;
//     create(&s, 100);
//
//     while()
//     if (t->l == NULL && t->r == NULL)
//
// }

int conta_nos(struct node *t) {
    int n = 0;

    if (t->l != NULL)
        n += conta_nos(t->l);
    if (t->r != NULL)
        n += conta_nos(t->r);

    return ++n;
}

int conta_folhas(struct node *t) {
    int n = 0;

    if (t->l == NULL && t->r == NULL)
        return 1;
    else {
        if(t->l != NULL)
            n += conta_folhas(t->l);
        if(t->r != NULL)
            n += conta_folhas(t->r);
    }

    return n;
}

// void remove( ABB * tree, int n ) {
//     tree->raiz = remove_no( tree->raiz , n );
// }
//
// struct node * remove_no( struct node *p, int n ) {
//     if(p == null)
//         return NULL;
//     if(n < p->data.n)
//         p->l = remove_no(p->l, n);
//     else if(n > p->data.n) {
//         p->r = remove_no(p->r, n);
//     } else {
//         if(p->r == NULL){
//             struct node * left = p->l;
//             free(p);
//             return left;
//         }
//         if(p->l == NULL){
//             struct node * right = p->r;
//             free(p);
//             return right;
//         }
//
//     }
// }

int altura( struct node *p ) {

}

int main() {
    ABB tree;
    int n = 8;
    int v[8] = {6,4,9,3,7,10,5,8};
    T dados;

    tree.raiz = NULL;

    for (int i = 0 ; i < n ; i++) {
        dados.n = v[i];
        insert(&tree, dados);
    }

    printf("pre-order: \n");
    pre_order_print(tree.raiz);
    printf("\n");
    printf("post-order: \n");
    pos_order_print(tree.raiz);
    printf("\n");
    printf("in-order: \n");
    in_order_print(tree.raiz);
    printf("\n");
    //
    // printf("in-order (iterative): \n");
    // n_rec_inorder(tree.raiz);
    // printf("\n");


    printf("N# de nodes: %d\n", conta_nos(tree.raiz));

    printf("N# de leaves: %d\n", conta_folhas(tree.raiz));


    return 0;
}
