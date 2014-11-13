#include "main.h"
#include "Functions.h"
  
    class MoveFunctions
    {
    public: 

        static CHESS_DLL_API void Move(char [][8], int currentN ,int current , int newN, int newL); 
		
		static CHESS_DLL_API bool isWithinScope(int Letter, int Number); // check the given location withing the board

		// moves of chess pieces
		static CHESS_DLL_API bool isValidRooksMove(int,int,int,int); // currentN, currentL, newN, newL
		static CHESS_DLL_API bool isValidBishopsMove(int,int,int,int);
		static CHESS_DLL_API bool isValidKnightsMove(int,int,int,int);
		static CHESS_DLL_API bool isValidPawnsMove(int,int,int,int,char[][8]); // as first time 2 cells long move is allowed board is used
		static CHESS_DLL_API bool isValidKingsMove(int,int,int,int);
		static CHESS_DLL_API bool isValidQueensMove(int,int,int,int);
		
    }; 
