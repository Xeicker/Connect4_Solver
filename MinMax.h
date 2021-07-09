#include "Board.h"

class MinMax{
private:
    short Min(Board b);
    short Max(Board b);
public:
    char Solve(Board b);
};