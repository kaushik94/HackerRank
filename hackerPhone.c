#include <stdio.h>

int main(){

	int N,i;
	unsigned long long x, sum=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
			scanf("%lld",&x);
			sum += x;
	}
	if(sum%2 == 1)
	printf("%lld.5\n",sum/2);
	else
	printf("%lld\n", sum/2);
	return 0;
}
