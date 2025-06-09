#include <stdio.h>
#include <string.h>
#include <math.h>
#include "RNG_Algorithm/lcg.h"

static int pre_rand = 0;

// glibc (used by GCC)
rand_Standard glibc_lcg = {1103515245, 12345, 2147483648};

int random_number_generator(
    int seed, 
    int pre_rand, 
    int low, 
    int high, 
    rand_Standard rand_stand,
    int (*algorithm)(rand_Standard, int, int, int)); // this is the wrapper function for the algorithm

int main(void)
{
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$^*%%&";
    int size_of_symbols = strlen(characters) - 1; // substract 1 to remove the size of null terminator from the string

    int len_of_password;
    printf("How many characters would you want to generate: ");
    scanf("%d", &len_of_password);
    getchar(); // remove the newline character from the input buffer

    char password[len_of_password+1];
    password[0] = '\0';
    for (int i = 0; i < len_of_password; i++)
    {
        int rand_number = random_number_generator(41, pre_rand, 0, size_of_symbols, glibc_lcg, lcg);

        password[i] = characters[rand_number];
    }

    password[len_of_password] = '\0';
    printf("Password - %s\n", password);

    FILE *fpassword;
    fpassword = fopen("password.txt", "w");
    fprintf(fpassword, "%s\n", password);
    fclose(fpassword);

    printf("Fine!\n");
    return 0;
}

int random_number_generator(
    int seed, 
    int pre_rand, 
    int low, 
    int high, 
    rand_Standard rand_stand,
    int (*algorithm)(rand_Standard, int, int, int))
{
    pre_rand = seed;
    int rand_num = algorithm(rand_stand, low, high, pre_rand);
    return rand_num;
}