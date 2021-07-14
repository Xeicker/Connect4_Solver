#include "MinMax.h"
#include<iostream>

MinMax::MinMax():memo(){};
MinMaxResult MinMax::Min(Board& b){
    return Max(b,false);
}
MinMaxResult MinMax::Max(Board& b,const bool playerA=true,short alpha,short beta){
    if(b.moves>=42){
        return std::make_tuple(0,0);
    }
    auto baux = b.board;
    auto bmaskaux = b.playedMask;
    short savedscore;
    MinMaxResult m{playerA? -64:64,3};
    for(auto &e : moves){
        if(b.PlayMove(static_cast<ushort>(e))){
            short score = b.Score();
            if(score==0){
                if(memo.TryGet(b,savedscore))
                    score = savedscore;
                else{
                    score = std::get<0>(Max(b,!playerA,alpha,beta));
                    memo.Add(b,score);
                }
            }
            short current =  std::get<0>(m);
            b.moves--;
            b.board = baux;
            b.playedMask = bmaskaux;
            if(playerA){
                if(score>alpha){
                    m=std::make_tuple(score,e);
                    alpha = score;
                }
            }
            else{
                if(score<beta){
                    beta = score;
                    m=std::make_tuple(score,e);
                }
            }
            if(alpha>=beta)
                break;   
        }
    }
    //std::cout<<std::get<0>(m)<<","<<static_cast<int>(std::get<1>(m))<<std::endl;
    
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