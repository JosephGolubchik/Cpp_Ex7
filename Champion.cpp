#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
	uint n=board.size()-1; 
	Coordinate c{0,0};
	if(board[c] == '.'){ // first coordinate is empty
		firstMove = true;
		return c;
	}
	if(firstMove){ // the champion starts
	
		for (int i = 0; i <= n; i++) {
			if(board[{i,i}] == '.') return {i,i};
		}
		
	}
	else{ // the champion didn't start
		if(board[{n,n}] == '.') return {n,n};
		
		if(board[{1,0}] == '.' && board[{0,n}] == '.'){
			return {0,n};
		}
		
		if(board[{0,1}] == '.' && board[{n,0}] == '.'){
			return {n,0};
		}
		
		if(board[{0,n}] != '.'){
			
			for (int i = 0; i <= n; i++) {
				if(board[{i,n}] == '.') return {i,n};
			}
			
		}
		
		if(board[{n,0}] != '.'){
			
			for (int i = 0; i <= n; i++) {
				if(board[{n,i}] == '.') return {n,i};
			}
			
		}
		
	}
	
	return {0,0};  // did not find an empty square - play on the top-left
}
