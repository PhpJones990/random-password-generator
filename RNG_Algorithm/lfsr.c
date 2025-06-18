#include <stdint.h>
#include <math.h>
#include "algorithm.h"

//Linear-Feedback Shift Register
//-------------------------------------------------------------------------------------------
rand_Standard first_taps = {32, 30, 26, 25};
rand_Standard second_taps = {32, 22, 2, 1};
//-------------------------------------------------------------------------------------------

static unsigned int state = 0;

int lfsr(rand_Standard taps, int low, int height, int seed)
{
    if (seed != -1)
    {
        state = seed;
    }

    unsigned int feedback = ((state >> (taps.a - 1)) ^ (state >> (taps.c - 1)) ^ (state >> (taps.m - 1)) ^ (state >> (taps.other - 1))) & 1;
    state = (state >> 1) | (feedback << (taps.a - 1)) ;
    return low + (state % (height - low + 1));
}