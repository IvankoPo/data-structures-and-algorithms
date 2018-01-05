#include <iostream>

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main() 
{
    std::cout << gcd(54,24);
    return 0;
}
