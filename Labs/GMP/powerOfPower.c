#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t x;
    mpz_t y;
    mpz_t z;
    mpz_init(x);
    mpz_init(y);
    mpz_init(z);

    printf("x ");
    gmp_scanf("%Zd", x);
    printf("y ");
    gmp_scanf("%Zd", y);
    printf("z ");
    gmp_scanf("%Zd", z);

    mpz_t r1;
    mpz_t r2;
    mpz_init(r1);
    mpz_init(r2);

    mpz_t i;
    mpz_init(i);
    mpz_set_ui(r1, 1);
    mpz_set_ui(r2, 1);

    for (mpz_set_ui(i, 1); mpz_cmp(i, z) <= 0; mpz_add_ui(i, i, 1))
    {
        mpz_mul(r1, r1, y);
    }

    for (mpz_set_ui(i, 1); mpz_cmp(i, r1) <= 0; mpz_add_ui(i, i, 1))
    {
        mpz_mul(r2, r2, x);
    }

    gmp_printf("\n%Zd", r2);
}

// x^(y^z)