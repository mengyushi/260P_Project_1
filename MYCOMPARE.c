#include <stdio.h>
#define COMPARELIMIT 10000
#define KLIMIT 100
double dshrandom( );

#include <stdarg.h>
int COMPARE(int arg1, int arg2, ...) {
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*	Comparisons to determine the biggest "k" array elements	*/
/*	COMPARE( 0,n ) initializes a random array of length n	*/
/*				all distinct values		*/
/*		returns  0 normally				*/
/*		returns -1 if n is out of range			*/
/*	COMPARE( x,y ) compares values of array[x] and array[y]	*/
/*		returns  1 if array[x] > array[y]		*/
/*		returns  2 if array[y] > array[x]		*/
/*		returns -1 if x or y is out of range		*/
/*	COMPARE( -1,k,Best[] ) checks whether Best[] contains	*/
/*			the indices of the biggest "k" in array	*/
/*		returns the number of comparisons performed	*/
/*			when the biggest "k" indices are okay	*/
/*		returns -1 if "k" is out of range		*/
/*		returns -1000 if any of the indices are wrong	*/
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
	static int number[6] = {0,6,4,3,2,5};
	// printf("Compared id %d => %d and %d => %d\n", arg1, number[arg1], arg2, number[arg2]);	
	if (number[arg1]>number[arg2])
		return(1);
	else	return(2);
}