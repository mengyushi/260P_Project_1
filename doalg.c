#include <stdio.h>
#include<stdbool.h>
#define MAXN 10000
#define MAXK 100

void shiftUp(int Heap[], int i) {

	int temp;

	printf("i = %d (i+1)/2)-1 = %d\n", i, ((i+1)/2)-1);

	while (i>0 && COMPARE(Heap[((i+1)/2)-1],Heap[i])==1) {
		printf("		====== Shift up\n");
		temp = Heap[i];
		Heap[i] = Heap[((i+1)/2)-1];
		Heap[((i+1)/2)-1] = temp;
		i = ((i+1)/2)-1;
	}
	return;
}

void shiftDown(int Heap[], int i, int k) {
	// printf("			====== Shift down i = %d k = %d\n", i, k);
	int temp, l, r, leftIdx, rightIdx;

	while (((i+1)*2-1)<k) {
		// printf("`````````");
		leftIdx = Heap[((i+1)*2-1)];
		if (((i+1)*2)<k) {
			rightIdx = Heap[((i+1)*2)];


			l = COMPARE(leftIdx,Heap[i]);
			r = COMPARE(rightIdx,Heap[i]);

			if (l==2 && r==2){
				if (COMPARE(leftIdx,rightIdx)==1){
					temp = Heap[i];
					Heap[i] = Heap[rightIdx];
					Heap[rightIdx] = temp;
					i=r;
				}else{
					temp = Heap[i];
					Heap[i] = Heap[leftIdx];
					Heap[leftIdx] = temp;	
					i=l;				
				}
			}else{
				if (l==2) {
					temp = Heap[i];
					Heap[i] = Heap[leftIdx];
					Heap[leftIdx] = temp;	
					i=l;				 	
				}
				if (r==2) {
					temp = Heap[i];
					Heap[i] = Heap[rightIdx];
					Heap[rightIdx] = temp;		
					i=r;		 	
				}
			}
		}else{
			l = COMPARE(leftIdx,i);
			if (l==2) {
				temp = Heap[i];
				Heap[i] = Heap[leftIdx];
				Heap[leftIdx] = temp;	
				i=l;				 	
			}else{
				break;
			}			
		}
	}
	return;
}

int doalg(int n, int k, int Best[]) {
	puts("		====== HERE ENTERED DOALG ======");
	
	int i,j,m;
	int Heap[k];

	static int number[5] = {6,4,3,2,5};

	j = 0;

	for (i=1; i<=n; i++) {

		printf("current i = %d\n", i);

		if (j<k) {
			Heap[j] = i;
			shiftUp(Heap, j);

			for (m=0; m<=j; m++) {
				printf("%d st value's index is %d and its value is ?\n",m,Heap[m]);	
			}

			j+=1;

		}
		else{

			printf("Heap is full. Current root with idx %d\n", Heap[0]);


			if (COMPARE(i,Heap[0])==1) {
				Heap[0] = i;
				for (m=0; m<k; m++) {
					printf("&&&&&&&&&& %d st value's index is %d and its value is ?\n",m,Heap[m]);	
				}				
				shiftDown(Heap, 0, k);
			}


			for (m=0; m<k; m++) {
				printf("%d st value's index is %d and its value is ?\n",m,Heap[m]);	
			}
		}
	}

	for (m=0; m<k; m++) {
		printf("%d st value's index is %d\n",m,Heap[m]);	
	}	


	puts("		====== HERE FINISHED DOALG ======");

	for (i=k-1;i>=0;i--){
		Best[i] = Heap[0];
		Heap[0] = Heap[i];
		// printf("Current i %d\n",i);
		shiftDown(Heap, 0, i);
	}

	for (m=0; m<k; m++) {
		printf("%d\n",Best[m]);	
	}	

	return(1);
}