#include <stdio.h>
#include <stdlib.h>

#define MAX 10

enum OPTION{    PUSH = 1,
                POP,
                TOP,
                EMPTY,
                FULL,
                PEEK};

typedef struct node{
    struct node *next;
    int item;
} stack;

void create (int stack[], int *pos) {
    stack[0] = 0;
    *pos = 0;
}

void push(int stack[], int *pos, int item) {
    if(*pos > 9) return;
    stack[*pos] = item;
    printf("%d inserted in pos %d\n", stack[*pos], *pos);
    *pos = *pos + 1;
}

void pop(int stack[], int *pos) {
    if(*pos == 0) return;
    stack[*pos] = 0;
    *pos = *pos - 1;
}


int top(int stack[], int *pos) {
    if(*pos == 0)
        return 0;
    else
        return stack[*pos - 1];
}

int empty(int stack[], int *pos) {
    if(*pos == 0) return 1;
    else return 0;
}


int full(int stack[], int *pos) {
    if(*pos > 9) return 1;
    else return 0;
}

void peek(int stack[], int *pos) {
    printf("\nPEEK:\n");
    for(int i = 0 ; i < *pos ; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[10];
    int item, pos, o = 1;

    create(stack, &pos);

    while(o >= 1 && o <= 6) {
        scanf("%d", &o);

        switch(o) {
            case PUSH:
                scanf("%d", &item);
                push(stack, &pos, item);
            break;
            case POP:
                pop(stack, &pos);
            break;
            case TOP:
                printf("Top item is: %d\n", top(stack, &pos));
            break;
            case EMPTY:
                printf("%d\n", empty(stack, &pos));
            break;
            case FULL:
                printf("%d\n", full(stack, &pos));
            break;
            case PEEK:
                peek(stack, &pos);
            break;
        }
    }

}
