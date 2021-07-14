#ifndef BOARD_H
#define BOARD_H
#include <array>

class Board{
private:
    const unsigned char columnMask{0xff};
    const unsigned long long int bottommask;
    const std::array<const unsigned long long int,7> bottomsinglemask
    {0x01,0x01'00,0x01'00'00,0x01'00'00'00,0x01'00'00'00'00
    ,0x01'00'00'00'00'00,0x01'00'00'00'00'00'00};
public:
    unsigned long long int board;
    unsigned long long int playedMask;
    short moves;
    bool playerA()const
    {return moves&1;};
    Board();
    void Print(bool complete=false)const;
    bool PlayMove(unsigned short column);
    short Winner()const;
    unsigned long long GetKey()const 
    {return board+playedMask+bottommask;};
    short CastToWinner(bool win)const
    {return win?(static_cast<short>(playerA())<<1)-1:0;};
    short Score()const
    {return Winner()*((1<<6)-moves);};
};
#endif