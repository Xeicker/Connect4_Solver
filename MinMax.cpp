#include "MinMax.h"
#include<iostream>

MinMax::MinMax():memo(){};
MinMaxResult MinMax::Min(Board& b){
    return Max(b,false);
}
MinMaxResult MinMax::Max(Board& b,const bool playerA=true,uint8_t alpha,uint8_t beta){
    //board full
    if(b.moves>=42){
        return DRAW_SCORE;
    }
    //Save variables to undo moves
    auto baux = b.board;
    auto bmaskaux = b.playedMask;
    uint8_t savedscore{DRAW_SCORE};
    MinMaxResult m{playerA? MIN_SCORE:MAX_SCORE};
    for(auto &e : moves){
        //Only consider playable moves
        if(b.PlayMove(static_cast<ushort>(e))){
            uint8_t score = b.Score();
            //No one has won get
            if(score==DRAW_SCORE){
                //if there is a saved result do not redo
                if(memo.TryGet(b,savedscore))
                    score = savedscore;
                else{
                    score = Max(b,!playerA,alpha,beta)&0xFF;
                    memo.Add(b,score);
                }
            }
            //Undo move
            b.moves--;
            b.board = baux;
            b.playedMask = bmaskaux;
            //--------

            //Maximising part of algorithm
            if(playerA){
                if(score>alpha){
                    m=score|(e<<8);
                    alpha = score;
                }
            }
            //Minimising part of algorithm
            else{
                if(score<beta){
                    beta = score;
                    m=score|(e<<8);
                }
            }
            //Alpha/Beta prunning
            if(alpha>=beta)
                break;   
        }
    }
    return m;
}
MinMaxResult MinMax::Solve(Board& b){
    if(b.playerA()){
        return Max(b);
    }
    else{
        return Min(b);
    }
}