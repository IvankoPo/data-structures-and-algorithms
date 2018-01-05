#include <iostream>

int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b & 1) 
        return binpow(a, b-1) * a;
    else {
        int c = binpow (a, b >> 1);
        return c * c;
    }
}