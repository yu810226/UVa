#include <stdio.h>
#include <string.h>

#define MAXDIGIT 10

int read_from_str(int len,int* big,char* str);
/*void print_num(int len,int *big);*/
int count_carry(int* biga,int* bigb, int len);

int main (void) {
	
	char str_a[MAXDIGIT+1] = {"\0"};
	char str_b[MAXDIGIT+1] = {"\0"};
	int endornot_a = 0;
	int endornot_b = 0;
	int a[MAXDIGIT];
	int b[MAXDIGIT];
	int reslen = 0;
	int c = 0;
	
	while (scanf("%s %s",str_a,str_b)!=EOF) {

		endornot_a = read_from_str(strlen(str_a),a,str_a);
		endornot_b = read_from_str(strlen(str_b),b,str_b);

		if ((endornot_a==1)&&(endornot_b==1)){
			break;
		}		

		if (strlen(str_a) >= strlen(str_b)) {
			reslen = strlen(str_a);
		}else{
			reslen = strlen(str_b);
		}
		
		/*
		printf("reslen:%d\n",reslen);
		
		print_num(strlen(str_a),a);
		print_num(strlen(str_b),b);
		*/

		c = count_carry(a,b,reslen);
		
		if  (c == 0) {
			printf("No carry operation.\n");
		}else if (c == 1){
			printf("1 carry operation.\n");
		}else{
			printf("%d carry operations.\n",c);
		}

	}
	
	return 0;
}

int read_from_str(int len,int* big,char* str){
	int i = 0;
	int endornot = 0;
	memset(big,0,sizeof(int)*MAXDIGIT);
	
	/*printf("%d\n",len);*/
	for (i = len-1; i >= 0 ; --i){
		big[len-1-i]=str[i]-48;
		/*
		printf("str[%d]:%c\n",i,str[i]);
		printf("big[%d]:%d\n",len-1-i,big[len-1-i]);
		*/
	}

	if ((len==1)&&(big[0]==0)){
		/*printf("num is 0\n");*/
		/*return 0;------>errror*/
		/*Control reaches end of non-void function. This means that there should be some value return*/
		/*But there isn't. So the UVa online judge makes the code WA*/
		/*Sol: Make the func. returns value  every time------>add endornot value*/
		
		endornot = 1;
	}
	
	return endornot;
}

/*
void print_num(int len,int *big){
	int i = 0;

	for (i = len-1; i >= 0; --i) {
		printf("%d",big[i]);
	}
	printf("\n");
}
*/

int count_carry(int* biga,int* bigb,int len){
	int i = 0;
	int carry = 0;
	int count = 0;

	/*printf("%d\n",len);*/
	for (i = 0; i < len; i++) {
		/*
		printf("biga[%d]:%d\n",i,biga[i]);
		printf("bigb[%d]:%d\n",i,bigb[i]);
		*/
				
		carry = (biga[i] + bigb[i] +carry) / 10;

		if (carry > 0){
			count++;
		}

	}

	return count;
}
