#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {

	List L = MakeEmpty();

	Insert(L, 15, L+1);

	if( IsEmpty(L) )
		printf("The is list is empty.");

	return 0;
}

