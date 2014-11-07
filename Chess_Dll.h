#ifdef CHESS_DLL_EXPORTS
#define CHESS_DLL_API __declspec(dllexport) 
#else
#define CHESS_DLL_API __declspec(dllimport) 
#endif


  
    class Functions
    {
    public: 

        static CHESS_DLL_API void Move(char [][8], int ,int , int, int); 
      
    };
