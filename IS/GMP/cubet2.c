#include <stdio.h>
#include <gmp.h>

int main() {
	mpz_t cube, num;
	mpz_init(cube);
	mpz_init(num);

	printf("Enter n ");
	gmp_scanf("%Zd", num);

	int i;

	mpz_set_ui(cube, 1);
	mpz_pow_ui(cube, num, 3);
	gmp_printf("%Zd", cube);
}
