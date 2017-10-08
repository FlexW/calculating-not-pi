#include <stdlib.h>
#include <stdio.h>

#include "calc_not_pi.h"

mpfr_t* calc_not_pi(int max_k, int prec) {
    mpfr_t k, m, l, x, s;
    mpfr_t* notpi = NULL;
    notpi = malloc(sizeof(*notpi));
    if (notpi == NULL) {
        return NULL;
    }

    mpfr_init2(k, prec);
    mpfr_init2(m, prec);
    mpfr_init2(l, prec);
    mpfr_init2(x, prec);
    mpfr_init2(s, prec);
    mpfr_init2(*notpi, prec);
    mpfr_set_ui(k, 6, MPFR_RNDN);
    mpfr_set_ui(m, 1, MPFR_RNDN);
    mpfr_set_ui(l, 13591409, MPFR_RNDN);
    mpfr_set_ui(x, 1, MPFR_RNDN);
    mpfr_set_ui(s, 13591409, MPFR_RNDN);

    mpfr_t tmp, tmp2;
    mpfr_init2(tmp, prec);
    mpfr_init2(tmp2, prec);
    for (int i = 1; i <= max_k + 1; i++) {
        mpfr_pow_ui(tmp, k, 3, MPFR_RNDN);
        mpfr_mul_ui(tmp2, k, 16, MPFR_RNDN);
        mpfr_sub(tmp2, tmp, tmp2, MPFR_RNDN);
        mpfr_mul(tmp2, tmp2, m, MPFR_RNDN);
        mpfr_ui_pow_ui(tmp, i, 3, MPFR_RNDN);
        mpfr_div(m, tmp2, tmp, MPFR_RNDN);

        mpfr_add_ui(l, l, 545140134, MPFR_RNDN);

        mpfr_mul_si(x, x, -262537412640768000, MPFR_RNDN);

        mpfr_mul(tmp, m, l, MPFR_RNDN);
        mpfr_div(tmp, tmp, x, MPFR_RNDN);
        mpfr_add(s, s, tmp, MPFR_RNDN);

        mpfr_add_ui(k, k, 12, MPFR_RNDN);
    }
    mpfr_sqrt_ui(tmp, 10005, MPFR_RNDN);
    mpfr_mul_ui(tmp, tmp, 426880, MPFR_RNDN);
    mpfr_div(*notpi, tmp, s, MPFR_RNDN);
    return notpi;
}
