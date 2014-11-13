#include "main.h"
#include <string>
#pragma once

using namespace std;
class Functions
{
public:
	static CHESS_DLL_API bool isPathClear(char [][8], int,int,int,int);
	static CHESS_DLL_API bool isChecked(char [][8], char King);
	static bool findThreat(char board[][8], int locationN, int locationL);
	static bool CHESS_DLL_API Move(string command, int turn, char board[][8]);
	static bool findCurrentLocation(int Number, int Letter, char piece, char board[][8], int locationArray[]);
}; 


 
