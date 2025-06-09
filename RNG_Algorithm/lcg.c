#include <math.h>
#include "lcg.h"

// pre_rand should be static int and it should be assign the seed value initially

int lcg(llint a, llint c, llint m, int low, int high, int pre_rand)
{
    int x = pre_rand;
    x = (a * x + c) % m;
    int scaled_x = low + (x % (high - low + 1));
    pre_rand = x;
    return scaled_x;
}