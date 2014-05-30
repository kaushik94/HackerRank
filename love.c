#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

unsigned long solve(){

		char * string;
		string = malloc(10002*sizeof(char));
		scanf("%s",string);
		unsigned long length = strlen(string);
		unsigned long i,j,mid;
		if(length%2 == 0){
			mid = length/2;
			i = mid-1;
			j = mid;
		}
		else{
			mid = length/2;
			i = mid-1;
			j = mid+1;
		}
		unsigned long op=0;
		while((j != length) && (i != -1)){
					op += abs(string[i] - string[j]);
			i--;
			j++;
		}
		
		return op;
}

int main(){

	int T,i;
	scanf("%d",&T);
	unsigned long Ans[T];
	for(i=0;i<T;i++)
		Ans[i] = solve();
	for(i=0;i<T;i++)
		printf("%lu\n",Ans[i]);
}
