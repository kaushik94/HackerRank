#include <stdio.h>
/*
 *segfault, change int [] declarations to malloc calls.
 */
int main(){
	
	int An, Bn,i;
	scanf("%d",&An);
	int A[An];
	for(i=0;i<An;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&Bn);
	int B[Bn];
	for(i=0;i<Bn;i++){
		scanf("%d",&B[i]);	
	}
	printf("here\n");
	int j=0;
	i=0;
	int C[100];
	int count = 0;
	/*sort arrays before this step.*/
	while((i != An) && (j != Bn)){
		if(A[i] != B[j]){
			C[count] = B[j];
			count++;
			j++;
		}
		else{
			j++;
			i++;
		}
	}
	for(i=0;i<count;i++)
		printf("%d ", C[i]);
	printf("\n");	
}
