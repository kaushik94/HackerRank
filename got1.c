#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
findPalind(char *arr)
{
     
    int i; 
    int count[28];
    for(i=0;i<28;i++)
		count[i] = 0;
    int flag = 0;
	
	for(i=0;i<strlen(arr);i++){
			int curr = arr[i] - '0';
			curr -= 49;
			count[curr] += 1; 
		}
		
	if(strlen(arr)%2 == 0){
			for(i=0;i<28;i++){
					if(count[i]%2 == 1){
							flag=1;break;}}
	}
	else{
			int one=0;
			for(i=0;i<28;i++){
					if(count[i]%2==1){
						if(one==0)one = 1;
						else{flag=1;break;}}}
	}
    if (flag==0)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
