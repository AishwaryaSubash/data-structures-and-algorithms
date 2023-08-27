
#include <stdio.h>
#include <gmp.h>
int main()
{
    mpf_t c, a;
    mpf_init(c);
    mpf_init(a);

    printf("Enter a number : ");
    gmp_scanf("%Ff", a);
    
    mpf_sqrt(c, a);
    gmp_printf("%.20Ff\n", c);
    return 0;
}
