#include <iostream>
#include "Board.h"
#include "MinMax.h"

using std::cout;
using std::endl;

int main(){
    Board b;
    b.PlayMove(3);
    b.PlayMove(3);
    b.PlayMove(3);
    b.PlayMove(3);
    b.PlayMove(3);

    b.PlayMove(6);

    b.PlayMove(2);

    b.PlayMove(1);
    b.PlayMove(1);
    b.PlayMove(1);
    b.PlayMove(1);

    b.PlayMove(5);
    b.PlayMove(5);
    b.PlayMove(5);
    b.PlayMove(5);
    
    
    MinMax solver;
    for(int i = 0; i <=30 && b.Winner()==0; i++){
        auto R= solver.Solve(b);
        cout<<std::get<0>(R)<<","<<static_cast<int>(std::get<1>(R))<<endl;
        b.PlayMove(std::get<1>(R));
    }
    b.Print(true);
    cout<<b.Winner()<<endl;
    return 0;
}