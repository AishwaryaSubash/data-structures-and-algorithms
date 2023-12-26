#include <stdio.h>
#include <gmp.h>

int main() {
	mpz_t rn;
	mpz_init(rn);
	int i, seed = 643123;

	gmp_randstate_t rs;
	gmp_randinit_default(rs);
	gmp_randseed_ui(rs, seed);

	for (i=0 ; i<10 ; i++) {
		mpz_urandomb(rn, rs, 150);
		gmp_printf("%Zd\n", rn);
	}
	return 0;
	
}
