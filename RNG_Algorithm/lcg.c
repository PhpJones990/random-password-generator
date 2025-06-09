#include <math.h>
#include "lcg.h"

// pre_rand should be static int and it should be assign the seed value initially

static int pre_rand = 0;

int lcg(rand_Standard rand_stand, int low, int high, int seed)
{
    if (seed != -1) {  // Use -1 to mean "don't reseed"
        pre_rand = seed;
    }
    int x = pre_rand;
    x = (rand_stand.a * x + rand_stand.c) % rand_stand.m;
    int scaled_x = low + (x % (high - low + 1));
    pre_rand = x;
    return scaled_x;
}