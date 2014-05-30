#include <stdio.h>

int findPrimes(int N){
	
	int count=2,i,j;
	if((N == 1)||(N==2))
		return 0;
	for(i=3;i<=N;i++){
		int prime=1;
		for(j=3;j<i/2;j++){
				if(i%j == 0)
					{prime=0;break;}
		}
		if(prime==1)
			count++;
	}
	return count;
}

int recurrse(int N){
	
	if(N==0)
		return 1;
	if(N == 1)
		return 1;
	if(N==2)
		return 1;
	if(N == 3)
		return 1;
	else
		return recurrse(N-1) + recurrse(N-4);
	
}

int solveCase(){

		
		int N,ans,M;
		scanf("%d",&N);
		M = recurrse(N);
		ans = findPrimes(M);
		return ans;
}

int main(){

		int T,i, Ans[i];
		scanf("%d",&T);
		for(i=0;i<T;i++){
			Ans[i] = solveCase();
		}
		for(i=0;i<T;i++){
			printf("%d\n",Ans[i]);
		}
}
