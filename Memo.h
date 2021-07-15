#ifndef MEMO_H
#define MEMO_H

#include <unordered_map>
#include "Board.h"

class Memo{
private:
    std::unordered_map<unsigned long long,unsigned char> mem;
    int MAX_SIZE;
public:
    Memo();
    void Add(const Board& b,unsigned char score);
    bool TryGet(const Board& b,unsigned char& score)const;        
};

#endif