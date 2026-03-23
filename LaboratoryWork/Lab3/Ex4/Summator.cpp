#include "Summator.h"

int Summator::transform(int i) const 
{
    return i;
}

int Summator::sum(int N) const 
{
    int result = 0;
    for (int i = 1; i <= N; ++i) 
    {
        result += transform(i);
    }
    return result;
}