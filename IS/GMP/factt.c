#include <stdio.h>
#include <gmp.h>

int main() {
	mpz_t fact, num, i;
	mpz_init(fact);
	mpz_init(num);
	mpz_init(i);

	printf("Enter n ");
	gmp_scanf("%Zd", num);

	mpz_set_ui(i, 1);
	mpz_set_ui(fact, 1);

	while (mpz_cmp(i, num)<= 0) {
		mpz_mul(fact, fact, i);
		mpz_add_ui(i, i, 1);
	}
	gmp_printf("%Zd", fact);
}
