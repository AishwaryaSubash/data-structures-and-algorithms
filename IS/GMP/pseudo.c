#include <stdio.h>
#include <gmp.h>
int main()
{
    mpz_t rand_num;
    mpz_init(rand_num);
    int i, seed = 5455345;

    gmp_randstate_t r_state;
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
    
    for (i = 0; i < 10; i++)
    {
        mpz_urandomb(rand_num, r_state, 150);
        gmp_printf("%d %Zd\n", i + 1, rand_num);
    }

    gmp_randclear(r_state);
    mpz_clear(rand_num);
    return 0;
}
