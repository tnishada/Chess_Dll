#include "StdAfx.h"
#include "Functions.h"
#include "MoveFunctions.h"
#include <iostream>
#include <cmath>
#include <locale>
#include <string>

using namespace std;
bool Functions::isPathClear(char board[][8], int currentN, int currentL, int newN, int newL)
{
	
	if(abs(currentN-newN)==abs(currentL-newL))// bishops move
	{ 
		
		int NFactor = (currentN<newN) ? 1 : -1;
		int LFactor = (currentL<newL) ? 1 : -1;

		while(currentN!=(newN-NFactor))
		{		
			currentN += NFactor;
			currentL += LFactor;

			if(board[currentN][currentL]!='0')
			{
				return false;
			}
		}	

		return true;
	}

	if(currentN==newN || newL==currentL)// rooks move
	{ 
		
			int factor;
			if(currentN==newN)
			{				
				factor = (currentL<newL) ? 1 : -1;
				currentL+= factor;
			}else if(newL==currentL)
			{
				factor = (currentN<newN) ? 1 : -1;		
				currentN+= factor;
			}

			
			while( !(currentL==newL && currentN==newN))
			{
				if(board[currentN][currentL]!='0'){
					return false;
				}

				if(currentN==newN)
				{						
					currentL+= factor;
				}else if(newL==currentL)
				{						
					currentN+= factor;
				}

			}

		return true;
	}

	return false; // if neither of above conditions are satisfied
}


bool Functions::isChecked(char board[][8], char King){ // under construction

		int locationN,locationL; // kings location number and letter
		
		// find the location of the king
		for(locationN=0;locationN<8;locationN++)
		{
			for(locationL=0;locationL<8;locationL++)
			{
				if(King==board[locationN][locationL])
				{					 					
					break;
				}
			}
			if(King==board[locationN][locationL]) // to stop outer loop
			{								
				break;
			}
		}
		
		return Functions::findThreat(board, locationN, locationL);
		
}

bool Functions::findThreat(char board[][8], int locationN, int locationL){
	// return true if a threat found
	 // factors are used to go through 8 directions
	int factorN = -1 , factorL = -1;
	locale loc;
	for(factorN=-1;factorN<=1;factorN++){
		for(factorL=-1;factorL<=1;factorL++){
			int tempL = locationL+factorL;
			int tempN = locationN + factorN;

			while( tempL>=0 && tempL<=7 && tempN>=0 && tempN<=7 && board[tempN][tempL]=='0' ){  // go thorugh all the empty cells in that direction
				tempL+= factorL;
				tempN+= factorN;
			}

			if( tempL>=0 || tempL<=7 || tempN>=0 || tempN<=7) break ;

			
			char foundPiece = toupper(board[tempN][tempL]);
			if(islower(board[locationN][locationL],loc)^islower(board[tempN][tempL],loc) ){ // found a piece of opposite color
			
				if(factorN==factorL){ // bishop or queens move
					if(foundPiece=='B' ||foundPiece=='b') return true;
				}
				else { // rook or queen
	
					if(foundPiece=='R' ||foundPiece=='b') return true;
				}
			}
		}
	}


	// pawn check and Knight check and opposite king check to be implemented
	// opposite kings check is used => to determine valid moves otherwise a king cannot check opposite king
	

	return false;
	
}

bool Functions::Move(string command, int turn, char board [][8]){ // turn refer the player 1=> white 0=> black

	char Letter = command.at(0);
	char Number = command.at(1);

	int iNumber = Number - 49; // converted letter and numbers to int of range 0 to 7
	int iLetter = Letter - 97;

	//cout<<"Number : "<<iNumber<<" letter "<<iLetter<<endl;
	int currentLocation[2]; // number, letter

	char piece = 'P';
	if(turn==1){
		piece = 'P';
	}
	else{
		piece = 'p';
	}
	

	if(Functions::findCurrentLocation(iNumber,iLetter,piece,board,currentLocation)){
		if(MoveFunctions::isValidPawnsMove(currentLocation[0],currentLocation[1],iNumber,iLetter, board)){
			MoveFunctions::Move(board,currentLocation[0],currentLocation[1],iNumber,iLetter);
		}
	}

	return true;
}

// true=> location found false => not found
bool Functions::findCurrentLocation(int Number, int Letter, char piece, char board[][8], int locationArray[]){

	if(piece=='p'||piece=='P'){
		if(piece=='P'){ // white pawn
			if(board[Number-1][Letter]=='P'){
				locationArray[0] = Number -1;
				locationArray[1] = Letter;
				return true;
			}
			else{
			
				if(board[Number-2][Letter]=='P'){
				locationArray[0] = Number -2;
				locationArray[1] = Letter;
				return true;
				}
			}
		}
		else{ // black pawn
			if(board[Number+1][Letter]=='p'){
				locationArray[0] = Number +1;
				locationArray[1] = Letter;
				return true;
			}
			else{
			
				if(board[Number+2][Letter]=='p'){
				locationArray[0] = Number +2;
				locationArray[1] = Letter;
				return true;
				}
			}
		}
	}

	char pieceType = (piece); // piecetype is used to implement their behavior
	toupper(pieceType);

	switch(pieceType){
		case 'R' : {
						int index;
						for(index=0;index<=7;index++){
							if(board[index][Letter]==piece){
								if(Functions::isPathClear(board,index,Letter,Number,Letter)){
									locationArray[0] = index;
									locationArray[1] = Letter;
									return true;
								}
							}

							if(board[Number][index]==piece){
								if(Functions::isPathClear(board,Number,index,Number,Letter)){
									locationArray[0] = Number;
									locationArray[1] = index;
									return true;
								}
							}
						}
							break;
				  }

		case 'N' : {
					break;
				 }

		case 'B' : {
					break;
				  }

		case 'Q' : {
					break;
				 }

		case 'K' : {
					break;
				  }
		default : return false;
	}

	return false;
}