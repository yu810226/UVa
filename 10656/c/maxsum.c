#include <stdio.h>
#include <stdlib.h>

int addnum (int *arr, int c);

int main(void){
	
	int n = 0;/*how many num are there in the num seq.*/	
	int i = 0;
	int countn = 0;/*nSeq size*/
	int countres = 0;/*resSeq size*/
	int res = 0;

	while (scanf("%d",&n)!=EOF){
		
		if (n == 0){
			break;
		}

		int *nSeq = malloc(n * sizeof (int));
		int *resSeq = malloc(n * sizeof (int));
		
		for (i = 0; i < n; i++){
			scanf("%d",&nSeq[i]);
		}
		
		countn = i;

		#ifdef DEBUG
			printf("count:%d\n",countn);
		#endif

		res = addnum(nSeq,countn);
		
		if (res == 0){
			printf("0");
		}else{			
			int j = 0;

			for (i = 0; i < n; i++){
				if (nSeq[i] != 0){
					resSeq[j] = nSeq[i];
					j++;
				}
			}
			
			countres = j;
			
			printf("%d",resSeq[0]);

			for (j = 1; j < countres; j++){
				printf("% d",resSeq[j]);
			}
			
		}
		
		printf("\n");
		
		free(nSeq);	
		free(resSeq);	

	}

	return 0;

}


int addnum (int *arr, int c){
	
	int l;
	int addres = 0;

	for (l = 0; l < c; l++){
		addres += arr[l]; 	
	}
	
	return addres;	
}

