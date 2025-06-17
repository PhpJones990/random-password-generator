#include <stdint.h>
#ifndef ALGO_H
#define ALGO_H

typedef struct
{
    uint64_t a;
    uint64_t c;
    uint64_t m;
    uint64_t other;
} rand_Standard;

int lcg(rand_Standard rand_stand, int low, int high, int seed);

int mwc(rand_Standard rand_stand, int low, int high, int seed);

int xorshift(rand_Standard shift_triplets, int low, int high, int seed);

int lfsr(rand_Standard taps, int low, int height, int seed);

#endif