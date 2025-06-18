#include "algorithm.h"
#include <stdint.h>
#include <math.h>

//Standard for MWC
// The seed and carry(c) is important!
//-------------------------------------------------------------------------------------------

//The format is {a, c, m}

//old_python_mwc = {4294957665, 12345, 4294967296};
//experimental = {987654321, 12345, 4294967296};
//-------------------------------------------------------------------------------------------

static unsigned int pre_rand = 0;
static uint64_t c = 0;

int mwc(int low, int high, int seed)
{
    if (seed != -1) {  // Use -1 to mean "don't reseed"
        pre_rand = seed;
        c = 12345;
    }
    uint64_t x = pre_rand;
    x = (4294957665 * x + c) % 4294967296;
    c = (uint64_t)(floor((4294957665 * x + c) / 4294967296));
    int scaled_x = low + (x % (high - low + 1));
    pre_rand = x;
    return scaled_x;
}