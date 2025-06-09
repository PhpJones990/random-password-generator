#include <math.h>
#include "lcg.h"

// pre_rand should be static int and it should be assign the seed value initially

static int pre_rand = 0;

int lcg(rand_Standard rand_stand, int low, int high, int seed)
{
    if (seed != -1) {  // Use -1 to mean "don't reseed"
        pre_rand = seed;
    }
    pre_rand = (rand_stand.a * pre_rand + rand_stand.c) % rand_stand.m;
    pre_rand = low + (pre_rand % (high - low + 1));
    return pre_rand;
}