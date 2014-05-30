#include<stdio.h>

int test(int N){

	int i;
	int A[N];
	int best;
	int bools[N];
	for(i=0;i<N;i++){
		scanf("%d",A[i]);
	}
	int best=A[N-1];
	for(i=N-2;i>=0;i--){
		if(A[i] > best)
			best = A[i];

	}
	return profit;
}

int main(){
	
	int T,i;
	scanf("%d",&T);
	int Ans[T];
	for(i=0;i<T;i++){
		int N;
		scanf("%d",&N);
		test(N);
	}

}
