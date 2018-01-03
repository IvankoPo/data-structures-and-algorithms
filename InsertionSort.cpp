#include <iostream>

void InsertSort(int* m, int len)
{
    for (int i = 1; i < len; i++)
        for (int j = i; j > 0 && m[j-1] > m[j]; j--)
            std::swap(m[j], m[j-1]);
}

int main() 
{

    int mass[10] = {13,24,43,21,22,17,28,14, 15, 20};
    InsertSort(mass, 10);
    for(int i: mass){
        std::cout << i << " ";
    }
    return 0;
}