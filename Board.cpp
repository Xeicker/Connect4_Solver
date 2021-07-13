#include "Board.h"
#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

Board::Board():
    board(0),
    bottommask(0x01010101010101),
    moves(0),
    playedMask(0){
}
void Board::Print(bool complete) const{
    for(int i = 0; i<7; i++){
        cout<<static_cast<bitset<8>>((board>>(i*8))&columnMask)<<endl;
    }
    if(complete){
        cout<<endl;
        for(int i = 0; i<7; i++){
            cout<<static_cast<bitset<8>>((playedMask>>(i*8))&columnMask)<<endl;
        }
    }
}
bool Board::PlayMove(ushort column){
    
    bool playable = ((playedMask>>(column*8))&columnMask)<0x3f;
    //player represented with 0 plays
    if(playable){
        playedMask |= bottomsinglemask[column]+playedMask;
        board ^= playedMask;
        moves++; 
    }
    return playable;
}
short Board::Winner()const {
    //horizontal win
    uint64_t aux = board&(board>>8);
    if((aux&(aux>>16))>0)
        return CastToWinner(!playerA);

    //diagonal 1 win
    aux = board&(board>>9);
    if((aux&(aux>>18))>0)
        return CastToWinner(!playerA);

    //diagonal 2 win
    aux = board&(board>>7);
    if((aux&(aux>>14))>0)
        return CastToWinner(!playerA);

    //vertical win
    aux = board&(board>>1);
    if((aux&(aux>>2))>0)
        return CastToWinner(!playerA);

    //draw
    return 0;
}