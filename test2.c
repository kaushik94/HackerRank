#include<stdio.h>
#include<stdlib.h>

int start_cities(unsigned long long N, unsigned long long ** City){

		unsigned long long temp;
		unsigned long long int curr=0;
		char string[1000];
		unsigned long long int i;
		
		for(i=0;i<N;i++)
			scanf("%llu ",&City[0][i]);
		
		for(i=0;i<N;i++)
			scanf("%llu ",&City[1][i]);
}

int print_cities(unsigned long long N, unsigned long long **City){

	unsigned long long i;
	for(i=0;i<N;i++){
		printf("%lld %lld\n",City[1][i], City[0][i]);
	}
}

int test_drive(unsigned long long C, unsigned long long N, unsigned long long **City){
	
	unsigned long long i,k=0,count=0;
	long  long *diff;
	diff = malloc(2*N*sizeof(long long));
	for(i=0;i<N;i++){
			diff[k] = City[0][i];
			diff[k+1] = -1*City[1][i];
			//printf("%lld %lld ",diff[k], diff[k+1]);
			k +=2;
	}
	int dosent_work = 0;
	unsigned long long fuels = 0;
	for(i=0;i<2*N;i++){
		fuels += diff[i];
	}
	if(fuels < 0)
		dosent_work = 1;
	
	if(dosent_work !=1){
	
	for(i=0;i<N;i++){
		long long sum=0;
		unsigned long long j;
		int loopa=0, loopb=0;
		long long first_worked = -1;
		
		for(j=2*i;j<2*N;j=j+1){
			//printf("%lld %lld %lld\n",i,j,sum);
			sum += diff[j];
			if(j==first_worked){
				loopb=0;break;}
			if(sum < 0){
				loopa=1;loopb=1;break;}	
			if(sum > C){
				sum = C;}		
		}
		
		if(loopa==0){
			for(j=0;j<=2*i;j++){
				//printf("%lld %lld %lld\n",i,j,sum);
				sum += diff[j];
				if(j==first_worked){
					loopb=0;break;}
				if(sum < 0){
				loopa=1;loopb=1;break;}
				if(sum > C){
					sum = C;}	
			}
		}
	if(loopb == 0){
			//printf("%lld\n",i);
			if(first_worked == -1)
				first_worked = 2*i;
				count++;
				}
	}
	}
	printf("%lld\n",count);
}



int main(){

	unsigned long long N, C;
	scanf("%lld %lld\n", &N, &C);
	unsigned long long i; 
	unsigned long long **City;
	City = malloc(2*sizeof(unsigned long long *));
	for(i=0;i<2;i++){
			City[i] = (unsigned long long *)malloc(N*sizeof(unsigned long long));
		}
	start_cities(N,City);
	//print_cities(N,City);
	test_drive(C,N,City);	
}
