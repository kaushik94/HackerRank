#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct automobile{

		unsigned long long _C;
		unsigned long long fuel; 
	}*car;

struct city{
		struct city *next;
		unsigned long ID;
		unsigned long long a;
		unsigned long long b;
	}*head, *start;

int init(){
	
	head = NULL;
	start = NULL;
	car = NULL;
}

int start_car(unsigned long long C){

		car = malloc(sizeof(struct automobile));
		car->_C = C;
		car->fuel = 0;
}

int start_cities(unsigned long long N){

		unsigned long long temp;
		unsigned long long int curr=0;
		struct city * tempC, * tempH;
		tempH = NULL;
		char string[1000];
		int i;
		int test[100];
		while ((NULL != fgets(string, sizeof string, stdin)) && (string[0] != '\n')){
				char test[100];
				int testI = 0;
				for(i=0;i<strlen(string);i++){
					if((string[i] != ' ') && (string[i] != '\n')) {
						test[testI] = string[i];
						testI++;
						}
					else{	
						test[testI] = '\n';
						unsigned long long temp;
						temp = atoll(test);
						testI = 0;
						
						tempC = malloc(sizeof(struct city));
						tempC->ID = curr;
						tempC->a = temp;
						
						if(head == NULL){
								head = tempC;
								tempH = tempC;
							}	
						else{
							if(curr == N-1){
								tempH->next = tempC;
								tempC->next = head;
								tempH = tempC;
							}
							else{
								tempH->next = tempC;
								tempH = tempC;
							}
						}		
						curr++;
						}
			}
			if(string[strlen(string) -1] == '\n')
					break;
		}
		
		
		struct city * itr;
		itr = head;
		while ((NULL != fgets(string, sizeof string, stdin)) && (string[0] != '\n')){
				char test[100];
				int testI = 0;
				for(i=0;i<strlen(string);i++){
					if((string[i] != ' ') && (string[i] != '\n')) {
						test[testI] = string[i];
						testI++;
						}
					else{	
						test[testI] = '\0';
						unsigned long long temp;
						temp = atoll(test);
						testI = 0;
						
						
						itr->b = temp;
						itr = itr->next;
						}
			}
			if(string[strlen(string) -1] == '\n')
					break;
		}
}

int print_cities(unsigned long long N){

	struct city * temp;
	temp = head; 
	do{
		printf("%lld, %lld\n", temp->a, temp->b);
		temp = temp->next;
		if(temp->ID == N-1){
			printf("%ld, %lld\n", temp->ID, temp->a);
			break;}
	}while(1==1);
	printf("%lld, %lld\n", temp->next->a, temp->next->b);
}

/*int test_drive(unsigned long long C){
	
	unsigned long long count=0;
	struct city *iter;
	iter = head;
	while(1==1){
		int lastround = 0;
		start_car(C);
		struct city *temp;
		temp = iter;
		unsigned long startID = temp->ID;
		while(1==1){
			if((car->fuel+temp->a) < car->_C)
				car->fuel += temp->a;
			else
				car->fuel = car->_C;
			//printf("%ld, %ld, %lld\n",startID, temp->ID, car->fuel);
			if((car->fuel > temp->b) || (car->fuel == temp->b)){
				
				temp = temp->next;
				car->fuel -= temp->b;
			}
			else
				break;
			if(startID == temp->ID){
				break;}	
		}
		iter = iter->next;
		if(iter->ID == 0)
			break;
	}
	
	printf("%lld\n", count);
}*/

int test_drive(){
	
	
}

int main(){

	init();
	unsigned long long N, C;
	scanf("%lld %lld\n", &N, &C);
	start_car(C);
	start_cities(N);
	/*print_cities(N);*/
	test_drive(C);
	
}
