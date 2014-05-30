#include <stdio.h>
#include <stdlib.h>

int solve(unsigned long long N, char * A){

	unsigned long long i,j;
	for(i=N;i>0;i--){
		if(i%3 == 0)
			if((N-i)%5 == 0)
				break;
	}
	//char A[N];
	if(i <= 0)
		if(N%3 == 0){i=N;}
		else if(N%5 == 0){i=0;}
		else{return -1;}

	for(j=0;j<N;j++){
		if(j<i)
			A[j] = '5';
		else
			A[j] = '3';
	} 
	printf("%s\n",A);
	return 0;
}

int main(){

	int T,i;
	scanf("%d",&T);
	char **A;
	A = malloc(T*sizeof(char *));

	for(i=0;i<T;i++){
		unsigned long long N;
		scanf("%lld\n",&N);
		solve(N,A[i]);
	}
	for(i=0;i<T;i++){
		printf("%s\n",A[i]);
	}
} 
