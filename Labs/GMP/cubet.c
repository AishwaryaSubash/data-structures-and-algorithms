#include <stdio.h>
#include <gmp.h>

int main() {
	int i;
	mpz_t cube, num;
	mpz_init(cube);
	mpz_init(num);

	mpz_set_ui(cube, 1);

	printf("Enter n ");
	gmp_scanf("%Zd", num);

	for (i=0 ; i<3 ; i++) {
		mpz_mul(cube, cube, num);
	}
	gmp_printf("%Zd", cube);
	return 0;
}
