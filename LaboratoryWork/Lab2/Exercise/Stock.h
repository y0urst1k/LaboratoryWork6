#pragma once
#include <vector>
#include "../SupportParts/Box.h"

class Stock
{
private:
    int next_id = 0;
    std::vector<Box> boxes;

public:
    void Add(int w, int v);
    int GetByW(int min_w);
    int GetByV(int min_v);
    int GetNextId() const;
};