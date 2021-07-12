#include <array>

class Board{
private:
    const unsigned char columnMask{0xff};
    unsigned long long int board;
    const unsigned long long int bottommask;
    unsigned long long int playedMask;
    const std::array<const unsigned long long int,7> bottomsinglemask
    {0x01,0x01'00,0x01'00'00,0x01'00'00'00,0x01'00'00'00'00
    ,0x01'00'00'00'00'00,0x01'00'00'00'00'00'00};
public:
    bool playerA;
    Board();
    void Print(bool complete=false)const;
    bool PlayMove(unsigned short column);
    short Winner()const;
    unsigned long long GetKey()
    {return board+playedMask+bottommask;};
    short CastToWinner(bool win)const
    {return static_cast<short>(playerA)*2-1;};
};