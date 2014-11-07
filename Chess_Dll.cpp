// Chess_Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Chess_Dll.h"
#include <iostream>

using namespace std;

void Functions::Move(char board[][8], int currentN, int currentL, int newN, int newL){ // Number, Letter 00-> a1 01 ->b1
	
	board[currentN][currentL] = board[newN][newL];
	board[currentN][currentL]  = '0';
}

bool Functions::isChecked(char board[][8], char King){

		int i,j;
		

		for(i=0;i<8  ;i++)
		{
			for(j=0;j<8;j++)
			{
				if(King==board[i][j])
				{
					 					
					break;
				}
			}

			if(King==board[i][j]) // to stop outer loop
			{
								
				break;
			}
		}

		cout<<i<<"  "<<j<<endl;
		return true;
}

