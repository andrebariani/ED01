#include <stdio.h>
#include "Heap.h"

int max_idade( T a, T b ) {
    return a.idade > b.idade;
}

int main() {
    priority_queue idade;

    inicializar( &idade, max_idade );

    T a1, a2, a3, a4, a5;
    a1.idade = 18;
    a2.idade = 18;
    a3.idade = 18;
    a4.idade = 18;
    a5.idade = 18;

}
