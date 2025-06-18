#include <stdint.h>
#include <math.h>
#include "algorithm.h"

//Common Shift Triplets
//-------------------------------------------------------------------------------------------
//first_triplet = {13, 7, 17};
//second_triplet = {10, 13, 10};
//thrid_triplet = {24, 21, 11};
//-------------------------------------------------------------------------------------------

static uint64_t state = 0;

int xorshift(int low, int high, int seed)
{
    if (seed != -1)
    {
        state = seed;
    }

    uint64_t x = state;
    x ^= (x << 13);
    x ^= (x >> 7);
    x ^= (x << 17);
    state = x;
    int scaled_x = low + (x % (high - low + 1));
    return scaled_x;
}