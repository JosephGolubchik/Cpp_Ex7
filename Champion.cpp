#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
	uint n=board.size(); //the champion starts
	Coordinate c{0,0};
	if(board[c] == '.'){ // we didn't start
		firstMove = true;
		return c;
	}
	if(firstMove){
		uint i = 0;
		while(board[{i,i}] != '.'){
			i++;
		}
		return {i,i};
	}
	else{
		if(board[{n,n}] == '.') return {n,n};
		
		if(board[{0,n}] != '.'){
			uint i = 0;
			while(board[{i,n}] != '.'){
				i++;
			}
			return {i,n};
		}
		
		if(board[{n,0}] != '.'){
			uint i = 0;
			while(board[{n,i}] != '.'){
				i++;
			}
			return {n,i};
		}
		
		if(board[{1,0}] == '.'){
			return {0,n};
		}
		else{
			return {n,0};
		}
	}
	
	return {0,0};  // did not find an empty square - play on the top-left
}