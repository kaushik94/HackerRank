#include <stdio.h>

char board [8][8];
int black[] = {};

int isWin(board, player){
		int i,win=0;
		if(player == 'h'){
			for(i=0;i<8;i++){
				if(board[7][i] == 'h'){
					return -1;
				}
			}
			int j,count=0;
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(((int)board[i][j]<123)&&(int(board[i][j] > 96)))
						count++;
				}
			}
			if(count != 8)
				return 1;
		}
		else if(player == 'H'){
			for(i=0;i<8;i++){
				if(board[7][i] == 'H'){
					return 1;
				}
			}
			int j,count=0;
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(((int)board[i][j]< 91)&&(int(board[i][j] > 64)))
						count++;
				}
			}
			if(count != 8)
				return -1;
		}
}		

int getMoves(char){


}

int main(){


}
