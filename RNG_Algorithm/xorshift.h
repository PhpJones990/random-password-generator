#include <stdint.h>
#include <math.h>
#include "lcg.h"

#ifndef XORSHIFT_H
#define XORSHIFT_H

int xorshift(rand_Standard shift_triplets, int low, int high, int seed);

#endif