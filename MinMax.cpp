#include "MinMax.h"
#include<iostream>

MinMax::MinMax():memo(){};
MinMaxResult MinMax::Min(Board& b){
    return Max(b,false);
}
MinMaxResult MinMax::Max(Board& b,const bool playerA=true,uint8_t alpha,uint8_t beta){
    if(b.moves>=42){
        return DRAW_SCORE;
    }
    auto baux = b.board;
    auto bmaskaux = b.playedMask;
    uint8_t savedscore{DRAW_SCORE};
    MinMaxResult m{playerA? MIN_SCORE:MAX_SCORE};
    for(auto &e : moves){
        if(b.PlayMove(static_cast<ushort>(e))){
            uint8_t score = b.Score();
            if(score==DRAW_SCORE){
                if(memo.TryGet(b,savedscore))
                    score = savedscore;
                else{
                    score = Max(b,!playerA,alpha,beta)&0xFF;
                    memo.Add(b,score);
                }
            }
            uint8_t current =  m&0xFF;
            b.moves--;
            b.board = baux;
            b.playedMask = bmaskaux;
            if(playerA){
                if(score>alpha){
                    m=score|(e<<8);
                    alpha = score;
                }
            }
            else{
                if(score<beta){
                    beta = score;
                    m=score|(e<<8);
                }
            }
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