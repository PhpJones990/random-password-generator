#include <stdio.h>
#include <string.h>

const int seed = 41;
static pre_rand = seed;

int main(void)
{
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$^*%%&";
    int size_of_symbols = strlen(characters) - 1;

    int len_of_password;
    printf("How many characters would you want to generate: ");
    scanf("%d", &len_of_password);
    getchar(); // remove the newline character from the input buffer

    printf("Fine!\n");
    return 0;
}