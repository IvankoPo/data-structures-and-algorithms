#include <iostream>

void resheto(bool mass[], int n)
{
    for (int i = 0; i < n; i++, mass[i] = true);
    for (int i = 2; i*i < n; i++)
        for (int j = i*i; j < n; j+=i)
            mass[j] = false;
}
int main()
{
    int n = 100;
    bool *mass = new bool[n];
    resheto(mass, n);
    for (int i = 0; i < 100; i++)
        if (mass[i] == true)
            std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
// 1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 