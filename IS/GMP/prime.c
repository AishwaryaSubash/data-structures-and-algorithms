#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t num;
    mpz_init(num);
    printf("Enter number : ");
    gmp_scanf("%Zd", num);
    mpz_t i;
    mpz_init(i);
    // mpz_set_str(i, "2", 10);
    mpz_t n2;
    mpz_init(n2);
    mpz_div_ui(n2, num, 2);
    for (mpz_set_ui(i, 2); mpz_cmp(i, n2) <= 0; mpz_add_ui(i, i, 1))
    {
        mpz_t mo;
        mpz_init(mo);
        // Set r = n - d * floor(n / d)
        mpz_fdiv_r(mo, num, i);         // %
        if (mpz_cmp_ui(mo, 0) == 0)
        {
            printf("\nNot Prime");
            return 1;
        }
    }
    printf("\nPrime");
    return 0;
}
