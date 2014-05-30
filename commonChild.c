#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b){

	return (a > b)? a:b;
}

int main(){

	char *A, * B;
	int i,j;
	A = malloc(5005 *sizeof(char));
	B = malloc(5005 *sizeof(char));
	scanf("%s", A);
	scanf("%s", B);
	int A_len = strlen(A);
	int **LCS = malloc((A_len+1)*sizeof(int*)); 
	for(i=0;i<=A_len;i++){
			LCS[i] = malloc (sizeof(int) * (A_len+1));
			for(j=0;j<=A_len;j++){
				if((i == 0) || (j == 0))
					LCS[i][j] = 0;
			
				else if(A[i-1] == B[j-1])
					LCS[i][j] = LCS[i-1][j-1] + 1;

				else
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}

	printf("%d\n", LCS[A_len][A_len]);
	}
