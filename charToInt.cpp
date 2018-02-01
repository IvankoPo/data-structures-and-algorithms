#include<iostream>

int charToInt(char* str)
{
    int res = NULL;
    for (str; *str != '\0'; res = res*10 + *str - 0x30, str++);
    return res;
}

int main() {
    char str[] = "1435";
    std::cout << charToInt(str) << std::endl;
    return 0;
}
