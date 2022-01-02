#include <iostream>

int main()
{
    int kg = 0;
    int five_cnt = 0;
    int three_cnt = 0;

    std::cin >> kg;

    while (kg) 
    {
        if (kg % 5 == 0) { five_cnt = kg / 5;  kg = 0;  break; }
        
        kg -= 3;
        three_cnt++;

        if (kg < 0) break;
    }

    if (kg == 0) std::cout << five_cnt + three_cnt;
    else std::cout << "-1";
}

