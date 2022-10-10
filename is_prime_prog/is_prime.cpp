#include "is_prime.hh"
#include <cmath>

bool is_prime(long int k)
{
    if (k <= 1)
    {
        return false;
    } else if (k == 2) {
        return true;
    }

    for (long int n = 2; n < sqrt(k) + 1; n += 1)
    {
        if ((k % n) == 0)
        {
            return false;
        }
    }

    return true;
}