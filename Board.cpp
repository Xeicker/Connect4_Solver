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
    //prints the board as if it were rotated 90 degrees
    for(int i = 0; i<7; i++){
        cout<<static_cast<bitset<8>>((board>>(i*8))&columnMask)<<endl;
    }
    //print the played moves so the user know if a 0 is because
    //there is no move or player 0 has a piece there
    if(complete){
        cout<<endl;
        for(int i = 0; i<7; i++){
            cout<<static_cast<bitset<8>>((playedMask>>(i*8))&columnMask)<<endl;
        }
    }
}
bool Board::PlayMove(ushort column){
    
    bool playable = ((playedMask>>(column*8))&columnMask)<0x3f;
    //player represented with 1 plays
    if(playable){
        //Adds a piece
        playedMask |= bottomsinglemask[column]+playedMask;
        //Flips all played positions, including the most recent
        //which was a 0 because there was nothing there and now it's
        //1 since player 1 played there
        board ^= playedMask;
        moves++; 
    }
    return playable;
}
bool Board::Winn()const {
    //horizontal win
    uint64_t aux = board&(board>>8);
    if((aux&(aux>>16))>0)
        return true;

    //diagonal 1 win
    aux = board&(board>>9);
    if((aux&(aux>>18))>0)
        return true;

    //diagonal 2 win
    aux = board&(board>>7);
    if((aux&(aux>>14))>0)
        return true;

    //vertical win
    aux = board&(board>>1);
    if((aux&(aux>>2))>0)
        return true;

    //draw
    return false;
}