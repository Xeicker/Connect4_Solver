#include <iostream>
#include "Board.h"

int main(){
    Board b;
    b.PlayMove(2);
    b.PlayMove(3);
    b.PlayMove(2);
    b.PlayMove(1);
    b.Print();
    return 0;
}