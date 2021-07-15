#include "Board.h"
#include "Memo.h"
#include <array>
#include <tuple>

typedef std::tuple<unsigned char,char> MinMaxResult;

class MinMax{
private:
    Memo memo;
    std::array<char,7> moves
    {3,4,2,5,1,6,0};
    MinMaxResult Min(Board& b);
    MinMaxResult Max(Board& b,bool playerA,unsigned char alpha=MIN_SCORE,unsigned char beta=MAX_SCORE);
public:
    MinMax();
    MinMaxResult Solve(Board& b);
};