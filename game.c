#include <stdio.h>
#include <stdlib.h>
//static int score=0;

int max(int A, int B, int C){
	
	printf("%d %d %d\n",A,B,C);
	if(A>B){
		if(A>C)
			return A;
		if(C>A)
			return C;		
	}
	else{
		if(C>B)
			return C;
		if(B>C)
			return B;
	}
	
	
}

int solve(int N,int player,int * A, int len,int  score[2]){
	
	if(player == 0)
		player = 1;
	else
		player = 0;

	if(N==len-1){
		/*if(player == 1){
			score[0] += A[len-1];
		}
		else
			score[1] += A[len-1];*/
		return A[len-1];	
	 }
	if(N==len-2){
		/*if(player == 1){
			score[0] += A[len-1]+A[len-2];
		}
		else
			//score[1] += A[len-1]+A[len-2];*/
		return A[len-1]+A[len-2];
	}
	if(N==len-3){
		/*if(player == 1){
			score[0] += A[len-1]+A[len-2]+A[len-3];
		}
		else
			score[1] += A[len-1]+A[len-2]+A[len-3];*/
		return A[len-1]+A[len-2]+A[len-3];
	}	
		
	else{
			if(player == 1){
					if(N+3 < len){
					score[0] = max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
					return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
					}
					else if(N+2 < len){
					score[0] = max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), -1);
					return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), -1);
					}
					else if(N+1 < len){
					score[0] = max(A[N]+solve(N+1, player, A,len, score), -1, -1);
					return max(A[N]+solve(N+1, player, A,len, score), -1, -1);
					}
			//return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
			}
			else{
			//score[1] += max(A[N]+solve(N+1, player, A, len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
			//return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
					if(N+3 < len){
					score[1] = max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
					return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), A[0]+A[1]+A[2]+solve(N+3, player, A,len, score));
					}
					else if(N+2 < len){
					score[1] = max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), -1);
					return max(A[N]+solve(N+1, player, A,len, score), A[N]+A[N+1]+solve(N+2, player, A,len, score), -1);
					}
					else if(N+1 < len){
					score[1] = max(A[N]+solve(N+1, player, A,len, score), -1, -1);
					return max(A[N]+solve(N+1, player, A,len, score), -1, -1);
					}
			}	
	}

}


int solveA(int player , int *A, int N, int len, int score[2]){
	
	printf("here %d %d\n",player, N);
	if(N==len-1)
		return A[N];
		
	/*if(N==len-2)
			return A[N]+A[N+1];
		
	if(N==len-3)
			return A[N]+A[N+1]+A[N+2];*/	
		
	if(player == 0){
		printf("haan :)\n");
		if(N+3<len){
		score[0] = max(A[N]+solveA(~player, A, N+1, len, score), A[N]+A[N+1]+solveA(~player, A, N+2, len, score), A[N]+A[N+1]+A[N+2]+solveA(~player, A, N+3, len, score));
		return 0;}
		else if(N+2<len){
		score[0] = max(A[N]+solveA(~player, A, N+1, len, score), A[N]+A[N+1]+solveA(~player, A, N+2, len, score), -1);
		return 0;}
		else if(N+1<len){
		score[0] = max(A[N]+solveA(~player, A, N+1, len, score), -1, -1);
		return 0;
		}
	}
	
	else if(player == -1){
		printf("haan :(\n");
		if(N+3<len){
		score[1] = max(A[N]+solveA(~player, A, N+1, len, score), A[N]+A[N+1]+solveA(~player, A, N+2, len, score), A[N]+A[N+1]+A[N+2]+solveA(~player, A, N+3, len, score));
		return 0;}
		else if(N+2<len){
		score[1] = max(A[N]+solveA(~player, A, N+1, len, score), A[N]+A[N-1]+solveA(~player, A, N+2, len, score), -1);
		return 0;}
		else if(N+1<len){
		score[1] = max(A[N]+solveA(~player, A, N+1, len, score), -1, -1);
		return 0;
		}	
	}
}


int main(){

	int T;
	scanf("%d",&T);
	int ans[T],i;
	for(i=0;i<T;i++){
		int N,j;
		scanf("%d",&N);
		int * A;
		A = malloc(N*sizeof(int));
		for(j=0;j<N;j++)scanf("%d",&A[j]);
		int score[2];
		score[0] = 0;
		score[1] = 0;
		solveA(0,A,0,N,score);
		ans[i] = score[1];
	}
	
	for(i=0;i<T;i++)
		printf("%d\n",ans[i]);
}
