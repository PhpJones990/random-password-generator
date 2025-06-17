#include <stdint.h>
#ifndef LCG_H
#define LCG_H

typedef struct
{
    uint64_t a;
    uint64_t c;
    uint64_t m;
    uint64_t other;
} rand_Standard;

int lcg(rand_Standard rand_stand, int low, int high, int seed);

#endif