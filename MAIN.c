#include <stdio.h>
#define MAXN 10000
#define MAXK 100
#include "COMPARE.c"
#include "doalg2.c"
int main(){
	int N = 11;
	int K = 5;
	int Best[MAXK];
	int k,n,flag,round,ct,loop,biggest,total;

	total = 0;
	biggest = -1;

	for (loop=0; loop<1; loop++) {
		printf(" ====== At loop=%d\n",loop);
		n = N;
		k = K;
		COMPARE(0,11);
		flag = doalg( 11, 5, Best);
		printf(" ====== flag=%d\n",flag);

	// 	if (flag==0) {
	// 		printf(" *** flagged error at loop=%d\n",loop);
	// 		return(0);
	// 	}
	// 	ct = COMPARE(-1,k,Best);
	// 	if (ct<=0) {
	// 		printf(" *** error at loop=%d\n",loop);
	// 		return(0);
	// 	}
	// 	if (ct>biggest) biggest=ct;
	// 	total += ct;
	}
	// printf("n=%5d,  k=%d:  maximum= %d,  avg=%8.2f\n",
	// 	N,K,biggest,(1.0*total)/1000);
	// fflush(stdout);

	printf("FINISHED");
}