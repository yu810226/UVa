#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void printout(int *arr, int size);
void sort(int *arr, int size);
void swap(int *a,int *b);

int main(void){

	int testn = 0;
	int n = 0;
	int i = 0;
	int j = 0;

	scanf("%d",&testn);

 	for ( i = 0; i < testn; i++){
		
		scanf("%d",&n);
		printf("There are %d numbers.\n",n);		

		int *arr = malloc( n * sizeof(int) );
 		for ( j = 0; j < n; j++){
			scanf("%d",&arr[j]);	
		}
		
		sort(arr,n);

	}

	return 0;
}

void printout(int *arr, int size){
	int k = 0;
	
	for( k = 0; k < size; k++){
		printf("% d",arr[k]);
	}
	printf("\n");
}

void sort(int *arr, int size){
	int k;
	int j;

	for (k = size; k > 0; k--){/*do size times*/	
		for (j = 0; j < k-1; j++){/*each time coompare one less element because the last (size-k) elements are already sorted */
			if ( arr[j] > arr[j+1] ){
				swap(&arr[j],&arr[j+1]);
			}
			
		}
	}

	#ifdef DEBUG
		printf("The sorted doorplate is:");
		printout(arr,size);
	#endif
}

void swap(int *a,int *b){
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;	
}
