#include <stdio.h>

int find(){

	int N,C,M;
	scanf("%d %d %d",&N, &C, &M);
	int W=0,chocs=0;
	while((W >= M)||(N >= C)){
		chocs++;
		if(N >= C){
			N -= C;
			W++;}
		else{
			W -= M;
			W++;			
			}
	}
	return chocs;
}

int main(){

	int T,i;
	scanf("%d",&T);
	int Ans[T];
	for(i=0;i<T;i++){
		Ans[i] = find();
	}

	for(i=0;i<T;i++){
		printf("%d\n",Ans[i]);
	}
}
