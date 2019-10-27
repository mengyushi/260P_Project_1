#include <stdio.h>
#include<stdbool.h>
#include "COMPARE.c"
#include "doalg2.c"

int main(){

	int k = 5;
	int i;

	static int Heap[5] = {7,8,11,9,10};

	for (i=0; i<k; i++) {

		printf("i = %d, swith_with = %d\n",i,k-1-i);

	// 	Best[i] = Heap[0];
		printf("POP %d\n",Heap[0]);
		Heap[0] = Heap[k-i-1];

		shiftDown(Heap, 0, k-i-1);
	}

	return(1);
}