#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
int canMove(char player, char board[8][8]){
	/*0 if no movable state for player, 1 if movable state*/
	int i,j;
	int _count=0;
	int won=1;
	for(i=0;i<8;i++){
		int broke =0;
		for(j=0;j<8;j++){
			if(board[i][j] == '-'){
			_count++;
			if(player == 'v'){
				if((board[i+1][j] == '-')&&(i+1<8)){
						_count++;broke=1;break;
				}
				if((board[i-1][j] == '-')&&(i-1>0)){
						_count++;broke=1;break;
				}
			}
			
			if(player == 'h'){				
				if((board[i][j+1] == '-')&&(j+1<8)){
						_count++;broke=1;break;
				}
				if((board[i][j-1] == '-')&&(j-1>0)){
						_count++;broke=1;break;
				}
			}
				
			}
		}
		if(broke == 1)
			break;
	}
	if(_count==0)
			won=0;		
			
	return won;
}

int moves(char player, char board[8][8], int vacant[4][68]){
	
	
	int i,j;
	int _count=0,curr=0;
	int avail =0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++){
			if(board[i][j] == '-'){
				_count++;	
			if(player == 'v'){
				if((board[i+1][j] == '-')&&(i+1<8)){
					vacant[0][curr] = i;
					vacant[1][curr] = j;
					vacant[2][curr] = i+1;
					vacant[3][curr] = j;
					curr++;
				}
			}

			if(player =='h'){
				if((board[i][j+1] == '-')&&(j+1<8)){
					//printf("%d %d\n",i,j);
					vacant[0][curr] = i;
					vacant[1][curr] = j;
					vacant[2][curr] = i;
					vacant[3][curr] = j+1;
					curr++;
				}
			}
				
			}
		}
	//printf("%d\n",curr);	
	/*for(i=0;i<curr;i++)
			printf("%d %d\n",vacant[0][i], vacant[1][i]);*/
	return curr;
}

/*h is maximizer, v is minimizer*/

int alpha_beta(char player, char board[8][8], int alpha, int beta, int depth){


			if(player == 'h')
					if(canMove('h', board) == 0)
							return -1;
			if(player == 'v')
					if(canMove('v', board) == 0)
							return 1;
			int i;
			int vacant[4][68];
			int num = moves(player, board, vacant);
			
			if(depth <= 0){
				printf("dude\n");
				if(player == 'h')
				return -1;
				else
				return 1;
			}
				
				if(player == 'h'){
					for(i=0;i<num;i++){
						//printf("%d %d %d %d   %d %d %d\n",vacant[0][i],vacant[1][i],vacant[2][i], vacant[3][i], i, depth, alpha);	
						//printf("%d %d\n",M[0], M[1]);
						board[vacant[0][i]][vacant[1][i]] = 'h';
						board[vacant[2][i]][vacant[3][i]] = 'h';
						int out = alpha_beta('v', board, alpha, beta, depth-1);
						board[vacant[0][i]][vacant[1][i]] = '-';
						board[vacant[2][i]][vacant[3][i]] = '-';
						if(out > alpha){
							alpha = out;
						}
						if(beta <= alpha){
							return alpha;}
						}
					return alpha;
				}
						
				else if(player =='v'){
					for(i=0;i<num;i++){
						board[vacant[0][i]][vacant[1][i]] = 'v';
						board[vacant[2][i]][vacant[3][i]] = 'v';
						int out  = alpha_beta('h', board, alpha, beta,depth-1);
						board[vacant[0][i]][vacant[1][i]] = '-';
						board[vacant[2][i]][vacant[3][i]] = '-';
						if(out < beta){
							beta = out;
						}
						if(alpha >= beta){
						return beta;}
					}
					return beta;
				}
	return 0;						
}

void nextMove(char player, char board[8][8]){
	
		int alpha=INT_MIN,beta=INT_MAX;
		int depth=3,curr=0;
		int i,j;
		int vacant[4][68];
		int num = moves(player, board, vacant);
		int A[3][num];
		if(num > 20){
			printf("%d %d\n", vacant[0][0], vacant[1][0]);
			return;
		}
		for(i=0;i<num;i++){
			
				if(player == 'h'){
					board[vacant[0][i]][vacant[1][i]] = 'h';
					board[vacant[2][i]][vacant[3][i]] = 'h';
					int out = alpha_beta('v', board, alpha, beta, depth);
					board[vacant[0][i]][vacant[1][i]] = '-';
					board[vacant[2][i]][vacant[3][i]] = '-';
					A[0][curr] = vacant[0][i];
					A[1][curr] = vacant[1][i];
					A[2][curr] = out;
					curr++; 
				}
				
				if(player == 'v'){
					board[vacant[0][i]][vacant[1][i]] = 'v';
					board[vacant[2][i]][vacant[3][i]] = 'v';
					int out = alpha_beta('h', board, alpha, beta, depth);
					board[vacant[0][i]][vacant[1][i]] = '-';
					board[vacant[2][i]][vacant[3][i]] = '-';
					A[0][curr] = vacant[0][i];
					A[1][curr] = vacant[0][j];
					A[2][curr] = out;
					curr++; 
				}
				
		}
		int best;	
		if(player == 'h')
			best = INT_MIN;
		else
			best = INT_MAX;
		
		int besti, bestj;
		printf("%d \n",curr);
		for(i=0;i<curr;i++){
			//printf("%d %d\n",A[0][i],A[2][i]);
			if( ((A[2][i] > best) && (player == 'h')) || ((A[2][i] < best) && (player == 'v')) ){
				best = A[2][i];
				besti = A[0][i];
				bestj = A[1][i];}	
		}
		printf("%d %d\n",besti,bestj);
}

int main(void) {

    int i;
    char player;
    char board[8][8];
    char line[8];
    scanf("%c", &player);

    for(i=0; i<8; i++) {
        scanf("%s", line);
        strncpy(board[i], line, 8);
    }
    i=0;
    nextMove(player,board);
    /*printf("%d\n",canMove(player, board));*/
    
    /*i=moves(player, board, vacant);
    int j;
    for(j=0;j<i;j++){
		printf("%d %d %d %d\n",vacant[0][j],vacant[1][j],vacant[2][j], vacant[3][j]);
	}*/
	//printf("%d\n",moves(player, board, vacant));
    return 0;
}
