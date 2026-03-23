#pragma once
class Box
{
private:
    int id;
    int weight;
    int volume;

public:
    Box(int id, int w, int v);
    int GetW() const;
    int GetV() const;
    int GetId() const;
};