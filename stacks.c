#include <stdio.h>

int stock(int * A, int N, int len, int price){
	
	if(N==len-1){
		
		if(price < A[N-1])
				return A[N-1];
		else
				return -price;
		
	}
	
	else{
		
		
				max(A[N] + stock(), )
	}
	
}

int main(){


}
