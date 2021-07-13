#include "Board.h"
#include <array>
#include <tuple>

typedef std::tuple<short,char> MinMaxResult;

class MinMax{
private:
    std::array<char,7> moves
    {3,4,2,5,1,6,0};
    MinMaxResult Min(Board& b);
    MinMaxResult Max(Board& b,bool playerA,short alpha=-64, short beta=64);
public:
    MinMaxResult Solve(Board& b);
};