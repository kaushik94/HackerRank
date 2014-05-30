#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>


int alternateFill(char player, char board[8][8]);

int evalPosition(char player, char board[8][8]){
	/*0 if no movable state for player, 1 if movable state*/
	int i,j;
	int _TotalCount=0,_count,_HCount=0,_VCount=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j] == '-'){
			
				if((board[i+1][j] == '-')&&(i+1<8)){
						_TotalCount++;
						_VCount++;	
				}
				if((board[i-1][j] == '-')&&(i-1>0)){
						_TotalCount++;
						_VCount++;
				}
							
				if((board[i][j+1] == '-')&&(j+1<8)){
						_TotalCount++;
						_HCount++;
				}
				if((board[i][j-1] == '-')&&(j-1>0)){
						_TotalCount++;
						_HCount++;
				}	
			}
		}
	}
	
		int ret = (int)(_HCount - _VCount);
		//ret = ret/_TotalCount;
		return ret;
}

int moves(char player, char board[8][8], int vacant[2][68]){
	
	int i,j;
	int curr=0;
	
	for(i=0;i<8;i++)
		for(j=0;j<8;j++){
			if(board[i][j] == '-'){	
			if(player == 'v'){
				if((board[i+1][j] == '-')&&(i+1<8)){
					vacant[0][curr] = i;
					vacant[1][curr] = j;
					curr++;
				}
			}

			if(player =='h'){
				if((board[i][j+1] == '-')&&(j+1<8)){
					vacant[0][curr] = i;
					vacant[1][curr] = j;
					curr++;
				}
			}
				
			}
		}
			
	/*for(i=0;i<curr;i++)
			printf("%d %d\n",vacant[0][i], vacant[1][i]);*/
	return curr;
}

int printBoard(char board[8][8], int depth){
	
	printf("\n depth:%d\n", depth);
	int i,j;
	for(i=0;i<8;i++){
		printf("\n");
		for(j=0;j<8;j++){
			printf("%c",board[i][j]);
		}
	}
	printf("\n");
}

int alpha_beta(char player, char board[8][8], int alpha, int beta, int depth){
	
		/*printf("%d\n", evalPosition(player, board));*/
		//printBoard(board, depth);
		int test[2][68];
		//printf("%d\n", depth);
		if(depth <= 0){
			return evalPosition(player, board);
		}
		else{
			int vacant[2][68];
			int num = moves(player, board, vacant);
			int i;
			if(player == 'h'){
					for(i=0;i<num;i++){
							board[vacant[0][i]][vacant[1][i]] = 'h';
							board[vacant[0][i]][vacant[1][i]+1] = 'h';
							int out = alpha_beta('v', board, alpha, beta, depth-1);
							board[vacant[0][i]][vacant[1][i]] = '-';
							board[vacant[0][i]][vacant[1][i]+1] = '-';
							if(out > alpha)
								alpha = out;
							if(beta <= alpha)
								break;
					return alpha;			
				}
			}
			else if(player == 'v'){
					for(i=0;i<num;i++){
							board[vacant[0][i]][vacant[1][i]] = 'v';
							board[vacant[0][i]+1][vacant[1][i]] = 'v';
							int out = alpha_beta('h', board, alpha, beta, depth-1);
							board[vacant[0][i]][vacant[1][i]] = '-';
							board[vacant[0][i]+1][vacant[1][i]] = '-';
							if(out < beta)
								beta = out;
							if(beta <= alpha)
								break;
					return beta;			
				}
			}	
		}
}

int alternateFill(char player, char board[8][8]){
	
	int i,j,curr=0;
	if(player == 'v'){
	for(j=0;j<8; j+=2){
		for(i=0;i<8;i++){
			if(board[i][j] == '-'){	
				if((board[i+1][j] == '-')&&(i+1<8)){
					printf("%d %d\n",i,j);
					curr++;
					return curr;
					}
				}
			}
		}
	}
	
	if(player == 'h'){
	for(i=0;i<8; i+=2){
		for(j=0;j<8;j++){
			if((board[i][j+1] == '-')&&(j+1<8)){
					printf("%d %d\n",i,j);
					curr++;
					return curr;
				}		
			}
		}
	}
	
	return curr;
}

void nextMove(char player, char board[8][8]){
	int vacant[2][68];
	int num = moves(player, board, vacant);
	int i;
	int depth = 1000;
	int res[num];
	int alpha = INT_MIN, beta = INT_MAX;
	
	if(alternateFill(player, board) == 0){
	if(player == 'h'){
		for(i=0;i<num;i++){
				board[vacant[0][i]][vacant[1][i]] = 'h';
				board[vacant[0][i]][vacant[1][i]+1] = 'h';
				int out = alpha_beta('v', board, alpha, beta, depth);
				board[vacant[0][i]][vacant[1][i]] = '-';
				board[vacant[0][i]][vacant[1][i]+1] = '-';
				res[i] = out;
		}	
	}
	if(player == 'v'){
		for(i=0;i<num;i++){
				board[vacant[0][i]][vacant[1][i]] = 'v';
				board[vacant[0][i]+1][vacant[1][i]] = 'v';
				int out = alpha_beta('h', board, alpha, beta, depth);
				board[vacant[0][i]][vacant[1][i]] = '-';
				board[vacant[0][i]+1][vacant[1][i]] = '-';
				res[i] = out;
		}	
	}
	int best, besti, bestj;
	if(player == 'h')
		best = INT_MAX;
	else
		best = INT_MIN;
		
	for(i=0;i<num;i++){
		if( ((res[i] >= best) && (player == 'v')) || ((res[i] <= best) && (player == 'h')) ){
			best = res[i];
			//printf("%d\n", best);
			besti = vacant[0][i];
			bestj = vacant[1][i];}	
	}
	printf("%d %d\n", besti, bestj);
	}
	
	else return;
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
    return 0;
}

