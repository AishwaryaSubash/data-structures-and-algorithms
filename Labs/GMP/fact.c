#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t n, fact, i;
    mpz_init(n);
    mpz_init(fact);
    mpz_init(i);

    printf("Enter a number: ");
    gmp_scanf("%Zd", n);
    mpz_set_ui(fact, 1);
    mpz_set_ui(i, 1);

    while (mpz_cmp(i, n) <= 0)      //i<n neg
    {
        mpz_mul(fact, fact, i);     //fact=fact*i
        mpz_add_ui(i, i, 1);        //i=i+1
    }
    
    gmp_printf("%Zd! = %Zd\n", n, fact);
    mpz_clear(n);
    mpz_clear(fact);
    mpz_clear(i);
    return 0;
}
