#include "convert.h"

void Convert::ackermann(mpz_t result, mpz_t m, mpz_t n)
{
    mpz_t one;
    mpz_init_set_ui(one, 1);

    if (mpz_cmp_ui(m, 0) == 0) {
        mpz_add_ui(result, n, 1);
    } else if (mpz_cmp_ui(m, 1) == 0) {
        mpz_add_ui(result, n, 2);
    } else if (mpz_cmp_ui(n, 0) == 0) {
        mpz_sub(m, m, one);
        ackermann(result, m, one);
    } else {
        mpz_t temp;
        mpz_init(temp);
        mpz_sub(n, n, one);
        ackermann(temp, m, n);
        mpz_sub(m, m, one);
        ackermann(result, m, temp);
        mpz_clear(temp);
    }

    mpz_clear(one);
}
