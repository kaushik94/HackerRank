#include<stdio.h>
void merge(unsigned long long [], unsigned long long, unsigned long long , unsigned long long);
void part(unsigned long long arr[],unsigned long long min,unsigned long long max)
{
 unsigned long long mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(unsigned long long arr[],unsigned long long min,unsigned long long mid,unsigned long long max)
{
  unsigned long long tmp[30];
  unsigned long long i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}

int main(){

	unsigned long long N,K,i;
	scanf("%lld %lld",&N,&K);
	unsigned long long arr[N];
	for(i=0;i<N;i++){
		scanf("%lld ",&arr[i]);
	}
	part(arr, 0, N-1);
	unsigned long long count = 0; 
	while(K>=0){
		count += 1;
		K -= arr[i];
	}
	printf("%lld\n", count);
}

