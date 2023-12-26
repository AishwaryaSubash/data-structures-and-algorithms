#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t num, cube;
    mpz_init(num);
    mpz_init(cube);

    printf("Enter a number: ");
    gmp_scanf("%Zd", num);
    mpz_pow_ui(cube, num, 3);
    mpz_t q;
    mpz_t r;

    // mpz_fdiv_qr(q, r, num, cube);
    mpz_set_ui(cube, 1);
    for (int i = 0; i < 3; i++)
        mpz_mul(cube, cube, num);

    gmp_printf("%Zd pow 3 = %Zd\n", num, cube);
    mpz_clear(num);
    mpz_clear(cube);
    return 0;
}
