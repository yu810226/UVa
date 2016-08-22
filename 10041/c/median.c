#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
void printout(int *arr, int size);
#endif
void sort(int *arr, int size);
void swap(int *a,int *b);
int median(int *arr, int size);
int distance(int *arr, int size, int med);

int main(void){
	
	int n = 0;

	scanf("%d",&n);

	int relatives = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	int totaldis = 0;

	for( i = 0; i < n; i++){
		scanf("%d",&relatives);
		#ifdef DEBUG
			printf("relatives:%d\n",relatives);
		#endif

		int * doorPlate = malloc(relatives * sizeof(int));
		for ( j = 0; j < relatives; j++){
			scanf("%d",&doorPlate[j]);
		} 	
		#ifdef DEBUG
			printf("The doorplate is:");
			printout(doorPlate,relatives);
		#endif

		sort(doorPlate,relatives);

		m = median(doorPlate,relatives);
		
		totaldis = distance(doorPlate,relatives,m);

		printf("%d\n",totaldis);
	}


	return 0;

}

#ifdef DEBUG
void printout(int *arr, int size){
	int k = 0;
	
	for( k = 0; k < size; k++){
		printf("% d",arr[k]);
	}
	printf("\n");
}
#endif


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

int median(int *arr, int size){
	int med = 0;	

	if ( (size%2) == 0 ){
		med = (arr[size/2-1] + arr[size/2]) / 2;
	}else{
		med = arr[size/2];
	}
	
	return med;
}

int distance(int *arr, int size, int med){
	int j = 0;
	int t = 0;
	
	for ( j = 0; j < size; j++ ){
		t += abs(med -arr[j]);
	}
	
	return t;
}
