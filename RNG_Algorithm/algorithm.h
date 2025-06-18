#include <stdint.h>
#ifndef ALGO_H
#define ALGO_H

int lcg(int low, int high, int seed);

int mwc(int low, int high, int seed);

int xorshift(int low, int high, int seed);

int lfsr(int low, int height, int seed);

#endif