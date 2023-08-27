#include <stdio.h>
#include <gmp.h>

int main() {
	mpz_t a, b, res;
	mpz_init(a);
	mpz_init(b);
	mpz_init(res);

	int ch;
	printf("1.Add\n2.Sub\n3.Mul\n4.Div\n");
	scanf("%d",&ch);

	printf("Enter n1 ");
	gmp_scanf("%Zd",a);
	printf("Enter n2 ");
	gmp_scanf("%Zd", b);

	char op;
	switch(ch) {
		case 1: {
			op='+';
			mpz_add(res, a, b);
			break;
		}
		case 2: {
			op='-';
			mpz_sub(res, a, b);
			break;
		}
		case 3: {
			op='*';
			mpz_mul(res, a, b);
			break;
		}
		case 4: {
			op='/';
			mpz_div(res, a, b);
			break;
		}
	}

	gmp_printf("%Zd %c %Zd %Zd", a, op, b, res);
	return 0;
}
