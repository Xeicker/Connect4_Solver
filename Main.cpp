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
    
    
    MinMax solver;
    for(int i = 0; i <=30 && !b.Winn(); i++){
        auto R= solver.Solve(b);
        cout<<(R&0xFF)<<","<<(R>>8)<<endl;
        b.PlayMove(R>>8);
    }
    b.Print(true);
    cout<<static_cast<int>(b.Winner())<<endl;
    return 0;
}