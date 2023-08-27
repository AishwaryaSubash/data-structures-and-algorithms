#include <stdio.h>
#include <gmp.h>

int main() {
	mpz_t num;
	gmp_randstate_t state;
	int i, seed=17634;
	mpz_init(num);
	gmp_randinit_default(state);
	gmp_randseed_ui(state,seed);
	for (int i=0 ; i<10 ; i++) {
//		gmp_scanf("%Zd",num);
		mpz_urandomb(num, state, 150);
		gmp_printf("%Zd\n", num);
	}
	
}
