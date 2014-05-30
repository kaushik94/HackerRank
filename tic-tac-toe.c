#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
/* Complete the function below to print 2 integers separated by a single space which will be your next move 
 */

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int min(int a, int b){
	
	if(a>b)
		return b;
	return a;	
}

int isWin(char player, char ar[3][3]){
	
	int i,countA=0,countB=0,countC=0,countD=0,countE=0,countF=0,countG=0,countH=0,won=0;
	for(i=0;i<3;i++){
		if(ar[i][0] == player){countA++;}
		if(countA == 3){won=1;break;}
		if(ar[i][1] == player){countB++;}
		if(countB == 3){won=1;break;}
		if(ar[i][2] == player){countC++;}
		if(countC == 3){won=1;break;}
		if(ar[0][i] == player){countD++;}
		if(countD == 3){won=1;break;}
		if(ar[1][i] == player){countE++;}
		if(countE == 3){won=1;break;}
		if(ar[2][i] == player){countF++;}
		if(countF == 3){won=1;break;}
		if(ar[i][i] == player){countG++;}
		if(countG == 3){won=1;break;}
		if(ar[i][2-i] == player){countH++;}
		if(countH == 3){won=1;break;}
	}
	if(won==0){
		countB = 0;
		for(i=0;i<3;i++)
			for(countA=0;countA<3;countA++)
				if(ar[i][countA] != '_')
					countB++;
		if(countB == 9)
			won = -1;
	}
	return won;
}

int min_max(char player, char ar[3][3]){
	
	/*printf("%d\n",isWin(player, ar));*/
	
	int i,j,bestValue;
	if(isWin('O', ar) == 1) return -1;
	if(isWin('X', ar) == 1) return  1;
	if(isWin(player, ar) == -1) return 0;
		
	if(player == 'X'){
		bestValue = INT_MIN;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(ar[i][j] == '_'){
						/*printf("yo\n",i,j);*/
						ar[i][j] = 'X';
						int out = min_max('O', ar);
						bestValue = max(bestValue, out);
						ar[i][j] = '_';			
				}
	}
	
	else if(player == 'O'){
		bestValue = INT_MAX;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(ar[i][j] == '_'){
						/*printf("%d %d\n",i,j);*/
						ar[i][j] = 'O';
						int out = min_max('X', ar);
						bestValue = min(bestValue, out);
						ar[i][j] = '_';			
			}
	}
	return bestValue;			
}

void nextMove(char player, char ar[3][3]){

	int A[3][9];
	int i,j;
	for(i=0;i<9;i++){
		A[0][i] = -100;
		A[1][i] = -100;
		A[2][i] = -100;
	}
	int count=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(ar[i][j] == '_')
				count++;
	if(count == 9){
			printf("%d %d\n", 1, 0);
			return;}		
	int B[3];
	int curr = 0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(ar[i][j] == '_'){
				/*printf("testing %d %d\n",i,j);*/
				ar[i][j] = player;
				
				int out;
				if(isWin(player, ar) == 1)
						{printf("%d %d\n",i,j);return;}
				if(player == 'X'){
					out = min_max('O', ar);}
				else{
					out = min_max('X', ar);}
				A[0][curr] = i;
				A[1][curr] = j;
				A[2][curr] = out;
				ar[i][j] = '_';
				curr++;
			}
		}
	}
	for(i=0;i<9;i++)
		printf("%d %d %d\n",A[0][i], A[1][i], A[2][i]);
	
	int best;	
	if(player == 'X')
			best = INT_MIN;
	else
			best = INT_MAX;
	int besti=-1,bestj=-1;		
	for(i=0;i<curr;i++){
		if( ((A[2][i] > best) && (player == 'X')) || ((A[2][i] < best) && (player == 'O')) ){
			best = A[2][i];
			besti = A[0][i];
			bestj = A[1][i];}	
	}
	printf("%d %d\n",besti, bestj);	
}

int main(void) {

    int i;
    char player;
    char board[3][3];

    //If player is X, I'm the first player.
    //If player is O, I'm the second player.
    scanf("%c", &player);

    //Read the board now. The board is a 3x3 array filled with X, O or _.
    for(i=0; i<3; i++) {
        scanf("%s[^\n]%*c", board[i]);
    }
  
   nextMove(player,board);
    return 0;
}
