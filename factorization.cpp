#include <iostream>
#include <vector>
#include <cmath>
void factor(int n)
{
    int s = sqrt(n);
    std::vector<int> res;

    for (int i = 0; i <= s; i++){

        while (n%i == 0){
            res.push_back(i);
            n /= i;
        }
    }

    if (n>1)
        res.push_back(n);

    for(int i: res)
        std::cout<< i << " ";
}

/*
    Факторизация или факторинг — это декомпозиция объекта
    в произведение других объектов или факторов, которые,
    будучи перемноженными, дают исходный
*/