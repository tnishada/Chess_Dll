// Chess_Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Chess_Dll.h"

void Functions::Move(char board[][8], int currentN, int currentL, int newN, int newL){ // Number, Letter 00-> a1 01 ->b1
	
	board[currentN][currentL] = board[newN][newL];
	board[currentN][currentL]  = '0';
}


