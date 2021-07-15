#ifndef BOARD_H
#define BOARD_H
#include <array>

#define MAX_SCORE 128
#define MIN_SCORE 0
#define DRAW_SCORE 64

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
    bool Winn()const;
    char Winner()const
    {return CastToWinner(Winn());};
    unsigned long long GetKey()const 
    {return board+playedMask+bottommask;};
    char CastToWinner(bool win)const
    {return win?(playerA()?2:0):1;};
    char Score()const
    {return Winn()?(playerA()?128-moves:moves):64;};
};
#endif