#include <math.h>
#include "algorithm.h"

// pre_rand should be static int and it should be assign the seed value initially
//Standard for LCG
//-------------------------------------------------------------------------------------------

//The format is {a, c, m}

// glibc (used by GCC)
//glibc_lcg = {1103515245, 12345, 2147483648};

// Park-Miller (a well-known minimal standard)
//park_miller = {16807, 0, 2147483647};


// Numerical Recipes LCG (Quick and Dirty)
//numerical_recipes = {1664525, 1013904223, 4294967296};

// Borland LCG (rand() in Old C Compilers)
//borland = {22695477, 1, 4294967296};

// MMIX (by Donald Knuth)
// rand_Standard mmix = {6364136223846793005, 1442695040888963407, 18446744073709551616};
//-------------------------------------------------------------------------------------------


static int pre_rand = 0;

int lcg(int low, int high, int seed)
{
    if (seed != -1) {  // Use -1 to mean "don't reseed"
        pre_rand = seed;
    }
    int x = pre_rand;
    x = (1103515245 * x + 12345) % 2147483648;
    int scaled_x = low + (x % (high - low + 1));
    pre_rand = x;
    return scaled_x;
}