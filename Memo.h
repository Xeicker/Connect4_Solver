#ifndef MEMO_H
#define MEMO_H

#include <unordered_map>
#include "Board.h"

class Memo{
private:
    std::unordered_map<unsigned long long,short> mem;
    int MAX_SIZE;
public:
    Memo();
    void Add(const Board& b,short score);
    bool TryGet(const Board& b, short& score)const;        
};

#endif