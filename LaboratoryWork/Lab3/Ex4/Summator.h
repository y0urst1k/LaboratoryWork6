#pragma once
class Summator
{
public:
    virtual int transform(int i) const;
    int sum(int N) const;
    virtual ~Summator() = default;
};