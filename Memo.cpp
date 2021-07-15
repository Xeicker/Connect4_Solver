#include "Memo.h"
#include <iostream>

Memo::Memo():MAX_SIZE(10'000'000){
};

void Memo::Add(const Board& b, uint8_t score){
    mem[b.GetKey()]=score;
    int size = mem.size();
    if(mem.size()>MAX_SIZE){
        mem.erase(mem.begin());
    }
}
bool  Memo::TryGet(const Board& b,uint8_t &score)const{
    auto foundscore = mem.find(b.GetKey());
    if(foundscore!=mem.end()){
        score = foundscore->second;
        return true;
    }
    return false;
}