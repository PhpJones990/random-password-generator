typedef long long int llint;

typedef struct
{
    llint a;
    llint c;
    llint m;
} rand_Standard;

int lcg(rand_Standard rand_stand, int low, int high, int pre_rand);