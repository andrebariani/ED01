#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"


char is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return symbol;
	}
	else
	{
	return 0;
	}
}

void calculate(char ex[]) {
    stack s;
    create(&s, strlen(ex));
    int res;

    for(int i = 0 ; i < strlen(ex) ; i++) {
        if( ex[i] > 64 || ex[i] < 90 ) {
            push(&s, ex[i]);
        }
        if(is_operator(ex[i]) != 0) {

        }
    }

}

int main() {
    int ex[20];


    scanf("\n%20[^\n]", ex);

    calculate(ex);

    printf("Postfix: %s\n", ex);

    // peek(&s);

    return 0;
}
