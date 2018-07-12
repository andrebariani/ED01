#include <stdio.h>
#include <stdlib.h>

#include "lista.h"



int main() {

	Lista letras;

	inicializa(&letras);

	insereInicio(&letras, 'A');
	insereInicio(&letras, 'B');
	insereInicio(&letras, 'C');
	insereInicio(&letras, 'D');
	insereInicio(&letras, 'E');
	insereInicio(&letras, 'A');
	insereInicio(&letras, 'B');
	insereInicio(&letras, 'C');
	insereInicio(&letras, 'B');
	insereInicio(&letras, 'D');
	insereInicio(&letras, 'E');
	//
	// char c;
	//
	// for( Iterador it = inicio(&letras); !acabou(&it); proximo(&it) ) {
	// 	elemento(&it,&c);
	// 	printf("%c\n", c);
	// }
	//
	// printf("------\n");
	// Iterador ini = inicio(&letras);
	// Iterador it = buscaProximo(&ini, 'B');
	// while( !acabou(&it) ) {
	// 	elemento(&it,&c);
	// 	printf("%c\n", c);
	// 	proximo(&it);
	// 	it = buscaProximo(&it, 'B');
	// }

	char c;
	Iterador ini = inicio(&letras);
	Iterador it = buscaProximo(&ini, 'E');
	elemento(&it ,&c);
	removeAntes(&it, &c);
	removeDepois(&it, &c);

	for( Iterador it = inicio(&letras); !acabou(&it); proximo(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
	}

	return 0;
}
