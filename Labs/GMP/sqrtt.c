#include <stdio.h>
#include <gmp.h>

int main() {
	mpf_t sq, num;
	mpf_init(sq);
	mpf_init(num);

	printf("Enter n ");
	gmp_scanf("%Ff", num);
	mpf_sqrt(sq, num);

	gmp_printf("Sqrt %Ff", sq);
	return 0;
}
