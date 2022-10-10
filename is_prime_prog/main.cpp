#include <iostream>
#include "is_prime.hh"

int main()
{
    long int i;

    while (std::cin >> i)
    {
        bool res = is_prime(i);
        std::cout << i << " is a prime: ";

        if(res)
        {
            std::cout << "True";
        } else {
             std::cout << "False";
        }

        std::cout << std::endl;
    }

    return 0;
}