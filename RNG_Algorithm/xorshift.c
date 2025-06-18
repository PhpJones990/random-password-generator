#include <stdint.h>
#include <math.h>
#include "algorithm.h"

//Common Shift Triplets
//-------------------------------------------------------------------------------------------
rand_Standard first_triplet = {13, 7, 17};
rand_Standard second_triplet = {10, 13, 10};
rand_Standard thrid_triplet = {24, 21, 11};
//-------------------------------------------------------------------------------------------

static uint64_t state = 0;

int xorshift(rand_Standard shift_triplets, int low, int high, int seed)
{
    if (seed != -1)
    {
        state = seed;
    }

    uint64_t x = state;
    x ^= (x << shift_triplets.a);
    x ^= (x >> shift_triplets.c);
    x ^= (x << shift_triplets.m);
    state = x;
    int scaled_x = low + (x % (high - low + 1));
    return scaled_x;
}