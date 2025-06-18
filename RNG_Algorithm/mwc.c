#include "algorithm.h"
#include <stdint.h>
#include <math.h>

//Standard for MWC
// The seed and carry(c) is important!
//-------------------------------------------------------------------------------------------
rand_Standard old_python_mwc = {4294957665, 12345, 4294967296};
rand_Standard experimental = {987654321, 12345, 4294967296};
//-------------------------------------------------------------------------------------------

static unsigned int pre_rand = 0;
static uint64_t c = 0;

int mwc(rand_Standard rand_stand, int low, int high, int seed)
{
    if (seed != -1) {  // Use -1 to mean "don't reseed"
        pre_rand = seed;
        c = 12345;
    }
    uint64_t x = pre_rand;
    x = (rand_stand.a * x + c) % rand_stand.m;
    c = (uint64_t)(floor((rand_stand.a * x + c) / rand_stand.m));
    uint64_t scaled_x = low + (x % (high - low + 1));
    pre_rand = x;
    return scaled_x;
}