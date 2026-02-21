#include "Stock.h"

void Stock::Add(int w, int v) 
{
    boxes.emplace_back(next_id++, w, v);
}

int Stock::GetByW(int min_w) 
{
    int best_id = -1;
    for (const auto& box : boxes) 
    {
        if (box.GetW() >= min_w) 
        {
            if (best_id == -1 || box.GetId() < best_id)
            {
                best_id = box.GetId();
            }
        }
    }
    if (best_id != -1) 
    {
        boxes.erase(std::remove_if(boxes.begin(), boxes.end(),
            [best_id](const Box& b) { return b.GetId() == best_id; }),
            boxes.end());
    }
    return best_id;
}

int Stock::GetByV(int min_v) 
{
    int best_id = -1;
    for (const auto& box : boxes) 
    {
        if (box.GetV() >= min_v)
        {
            if (best_id == -1 || box.GetId() < best_id) 
            {
                best_id = box.GetId();
            }
        }
    }
    if (best_id != -1) 
    {
        boxes.erase(std::remove_if(boxes.begin(), boxes.end(),
            [best_id](const Box& b) { return b.GetId() == best_id; }),
            boxes.end());
    }
    return best_id;
}

int Stock::GetNextId() const { return next_id - 1; }