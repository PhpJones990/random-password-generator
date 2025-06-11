#include <stdint.h>
#include <math.h>
#include "lcg.h"

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