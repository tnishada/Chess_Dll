#include "main.h"
#include "Functions.h"
class MoveFunctions{

public:
	static CHESS_DLL_API void Move(char board[][8], int currentN, int currentL, int newN, int newL);
	static CHESS_DLL_API bool isValidRooksMove(int currentN, int currentL, int newN, int newL);
	static CHESS_DLL_API bool isValidBishopsMove(int currentN, int currentL, int newN, int newL);
	static CHESS_DLL_API bool isValidKnightsMove(int currentN, int currentL, int newN, int newL);
	static CHESS_DLL_API bool isValidPawnsMove(int currentN, int currentL, int newN, int newL, char board[][8] );
	static CHESS_DLL_API bool isWithinScope(int N, int L);
	static CHESS_DLL_API bool isValidKingsMove(int currentN, int currentL, int newN, int newL);
	static CHESS_DLL_API bool isValidQueensMove(int currentN, int currentL, int newN, int newL);

};