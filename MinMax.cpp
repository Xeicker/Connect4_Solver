#include "MinMax.h"
#include<iostream>

MinMaxResult MinMax::Min(Board b){
    return Max(b,false);
}
MinMaxResult MinMax::Max(Board b,bool playerA=true){
    auto baux = b.board;
    auto bmaskaux = b.playedMask;
    MinMaxResult m{playerA? -1:1,3};
    for(auto &e : moves){
        if(b.PlayMove(static_cast<ushort>(e))){
            short winner = b.Winner();
            if(winner==0)
                winner = std::get<0>(Max(b,!playerA));
            short current =  std::get<0>(m);
            if(playerA){
                if(winner>=current)
                    m=std::make_tuple(winner,e);
                if(winner==1)
                    break;
            }
            else{
                if(winner<current)
                    m=std::make_tuple(winner,e);
                if(winner==-1)
                    break;
            }
        }
        b.playerA!=playerA;
        b.board = baux;
        b.playedMask = bmaskaux;
    }

    //std::cout<<std::get<0>(m)<<","<<static_cast<int>(std::get<1>(m))<<std::endl;
    return m;
}
MinMaxResult MinMax::Solve(Board b){
    if(b.playerA){
        return Max(b);
    }
    else{
        return Min(b);
    }
}