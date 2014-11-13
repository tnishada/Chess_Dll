// Chess_Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MoveFunctions.h"
#include <iostream>

using namespace std;

void MoveFunctions::Move(char board[][8], int currentN, int currentL, int newN, int newL){ // Number, Letter 00-> a1 01 ->b1
	
	board[newN][newL] = board[currentN][currentL] ;
	board[currentN][currentL]  = '0';
}


bool MoveFunctions::isValidRooksMove(int currentN, int currentL, int newN, int newL){ 
		//  letter(L) => column letter of the board
		// Number(N) => row number of the board

	if(currentL==newL && currentN==newN){ // both cells are same
		return false;
	}

	if(currentL==newL || currentN==newN){
		return true;
	}
	else{
		return false;
	}
		
}

bool MoveFunctions::isValidBishopsMove(int currentN, int currentL, int newN, int newL){

	if(currentL==newL && currentN==newN)// both cells are same
	{ 
		return false;
	}

	if(abs(currentL-newL)==abs(currentN-newN)){
		return true;
	}
	else{
		return false;
	}
}

bool MoveFunctions::isValidKnightsMove(int currentN, int currentL, int newN, int newL){

	if(currentL==newL && currentN==newN)// both cells are same
	{ 
		return false;
	}

	if(abs(currentN-newN)==1 && abs(currentL-newL)==2){
		return true;
	}
	else if(abs(currentL-newL)==1 && abs(currentN-newN)==2){
		return true;
	}
	else{
		return false;
	}
}

// only the move is implemented(cut is now implemented yet)
bool MoveFunctions::isValidPawnsMove(int currentN, int currentL, int newN, int newL, char board[][8] )// board is used to check the pawn's location
{ 
	if(currentL==newL && currentN==newN)// both cells are same
	{ 
		return false;
	}

	if(currentL!=newL){ // if pawn is moved horizontally (invalid move)
		return false;
	}

	if((board[currentN][currentL]=='P' && newN > currentN) ||( board[currentN][currentL]=='p' && currentN>newN))// capital p => white pawn, newN>currentN => moving direction is +
	{	// simple p => black pawn, newN<currentN => moving direction is -
		if(currentN==1 || currentN==6)// white pawn is not moved yet
		{ 
			if(abs(currentN-newN)==1 || abs(currentN-newN)==2)
			{
				return true;
			}			
		}
		else
		{ 
			if(abs(currentN-newN)==1)
			{
				return true;
			}
		}
	}
	
	return false;
}

bool MoveFunctions::isWithinScope(int N, int L){
	if(L>=0 && L<=7 && N<=7 && N>=0){
		return true;
	}
	else{
		return false;
	}
}

bool MoveFunctions::isValidKingsMove(int currentN, int currentL, int newN, int newL){
	
	if(currentL==newL && currentN==newN)// both cells are same
	{ 
		return false;
	}

	if(abs(currentN-newN)<=1 && abs(currentL-newL)<=1){ // king can move only 1 cell at any direction
		return true;
	}
	else{
		return false;
	}
}

bool MoveFunctions::isValidQueensMove(int currentN, int currentL, int newN, int newL){ // queen can move as a bishop or a rook

	if(MoveFunctions::isValidBishopsMove(currentN, currentL,  newN,  newL) || MoveFunctions::isValidRooksMove(currentN, currentL,  newN,  newL) ){
		return true;
	}
	else{
		return false;
	}
}