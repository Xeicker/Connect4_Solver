#include "MinMax.h"
#include<iostream>

MinMaxResult MinMax::Min(Board& b){
    return Max(b,false);
}
MinMaxResult MinMax::Max(Board& b,const bool playerA=true,short alpha,short beta){
    auto baux = b.board;
    auto bmaskaux = b.playedMask;
    MinMaxResult m{playerA? -64:64,3};
    for(auto &e : moves){
        if(b.PlayMove(static_cast<ushort>(e))){
            short score = b.Score();
            if(score==0)
                score = std::get<0>(Max(b,!playerA,alpha,beta));
            short current =  std::get<0>(m);
            b.moves--;
            b.board = baux;
            b.playedMask = bmaskaux;
            if(playerA){
                if(score>=current){
                    m=std::make_tuple(score,e);
                    alpha = score;
                }
            }
            else{
                if(score<current){
                    beta = score;
                    m=std::make_tuple(score,e);
                }
            }
            if(alpha>=beta )
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