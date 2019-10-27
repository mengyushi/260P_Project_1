#include <stdio.h>
#include<stdbool.h>
#define MAXN 10000
#define MAXK 100

void shiftUp(int Heap[], int i) {
	puts("		====== SHIFT UP START ======");

	int temp;

	printf("i = %d (i+1)/2)-1 = %d\n", i, ((i+1)/2)-1);
	printf("COMPARE = %d\n", COMPARE(Heap[((i+1)/2)-1],Heap[i]));

	while (i>0 && COMPARE(Heap[((i+1)/2)-1],Heap[i])==1) {
		printf(" ###### Shift up ###### \n");
		temp = Heap[i];
		Heap[i] = Heap[((i+1)/2)-1];
		Heap[((i+1)/2)-1] = temp;
		i = ((i+1)/2)-1;
	}
	return;
}

void shiftDown(int Heap[], int i, int k) {
	// printf("			====== Shift down i = %d k = %d\n", i, k);
	int temp, l, r, leftIdx, rightIdx,m;

	while (((i+1)*2-1)<k) {
		// printf("`````````");
		leftIdx = Heap[((i+1)*2-1)];
		if (((i+1)*2)<k) {
			rightIdx = Heap[((i+1)*2)];


			l = COMPARE(leftIdx,Heap[i]);
			r = COMPARE(rightIdx,Heap[i]);

			printf("leftIdx = %d, rightIdx = %d", leftIdx, rightIdx);

			if (l==2 && r==2){

				if (COMPARE(leftIdx,rightIdx)==1){

					temp = Heap[i];
					Heap[i] = rightIdx;
					Heap[((i+1)*2)] = temp;
					i=((i+1)*2);		

				}else{
					temp = Heap[i];
					Heap[i] = leftIdx;
					Heap[((i+1)*2-1)] = temp;	
					i=((i+1)*2)-1;		

					printf("\n\n\n\n\n");
					
					for (m=0; m<k; m++) {
						printf("&&&&&&&&&& %d st value's index is %d and its value is ?\n",m,Heap[m]);	
					}			
				}
			}else{
				if (l==2) {
					temp = Heap[i];
					Heap[i] = leftIdx;
					Heap[((i+1)*2-1)] = temp;	
					i=((i+1)*2)-1;				 	
				}
				if (r==2) {
					temp = Heap[i];
					Heap[i] = rightIdx;
					Heap[((i+1)*2)] = temp;		
					i=((i+1)*2);		 	
				}
			}
		}else{
			l = COMPARE(leftIdx,i);
			if (l==2) {
				temp = Heap[i];
				Heap[i] = leftIdx;
				Heap[((i+1)*2-1)] = temp;	
				i=((i+1)*2)-1;				 	
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

	j = 0;

	for (i=1; i<=n; i++) {
		printf("\n\n");
		printf("current i = %d\n", i);

		if (j<k) {
			Heap[j] = i;
			shiftUp(Heap, j);

			printf("	====== Shift up finished\n");

			for (m=0; m<=j; m++) {
				printf("%d st value's index is %d and its value is ?\n",m,Heap[m]);	
			}

			j+=1;

		}else{

			printf("Heap is full. Current root with idx %d\n", Heap[0]);


			if (COMPARE(i,Heap[0])==1) {
				Heap[0] = i;
				for (m=0; m<k; m++) {
					printf("&&&&&&&&&& %d st value's index is %d and its value is ?\n",m,Heap[m]);	
				}				
				shiftDown(Heap, 0, k);
			}

			printf("	====== Shift down finished\n");

			for (m=0; m<k; m++) {
				printf("%d st value's index is %d and its value is ?\n",m,Heap[m]);	
			}
		}
	}
	return(1);	
}