#include <stdint.h>
#include <math.h>
#include "algorithm.h"

//Linear-Feedback Shift Register
//-------------------------------------------------------------------------------------------
//first_taps = {32, 30, 26, 25};
//second_taps = {32, 22, 2, 1};
//-------------------------------------------------------------------------------------------

static unsigned int state = 0;

int lfsr(int low, int height, int seed)
{
    if (seed != -1)
    {
        state = seed;
    }

    unsigned int feedback = ((state >> 31) ^ (state >> 21) ^ (state >> 1) ^ state) & 1;
    state = (state >> 1) | (feedback << 31) ;
    return low + (state % (height - low + 1));
}