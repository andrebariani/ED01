#include "stack_list.h"
#include <stdio.h>

int main() {
    stack s;
    char v;
    create(&s,10);

    push(&s,'J');
    push(&s,'o');
    push(&s,'O');
    push(&s,'J');

    peek(&s);

    pop(&s,&v);

    peek(&s);

    pop(&s,&v);
    peek(&s);

    pop(&s,&v);

    return 0;
}
