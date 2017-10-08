#include <stdlib.h>
#include <stdio.h>

#include "calcpi.h"

mpfr_t* calc_pi(int max_k, int prec) {
    mpfr_t k, m, l, x, s;
    mpfr_t* pi = NULL;
    pi = malloc(sizeof(*pi));
    if (pi == NULL) {
        return NULL;
    }

    mpfr_init2(k, prec);
    mpfr_init2(m, prec);
    mpfr_init2(l, prec);
    mpfr_init2(x, prec);
    mpfr_init2(s, prec);
    mpfr_init2(*pi, prec);
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
        //mpfr_printf("k^3 = %.128Rf\n\n", tmp);
        mpfr_mul_ui(tmp2, k, 16, MPFR_RNDN);
        //mpfr_printf("k*16 = %.128Rf\n\n", tmp2);
        mpfr_sub(tmp2, tmp, tmp2, MPFR_RNDN);
        //mpfr_printf("tmp2-tmp = %.128Rf\n\n", tmp2);
        mpfr_mul(tmp2, tmp2, m, MPFR_RNDN);
        //mpfr_printf("m*tmp2 = %.128Rf\n\n", tmp2);
        mpfr_ui_pow_ui(tmp, i, 3, MPFR_RNDN);
        //mpfr_printf("i^3 = %.128Rf\n\n", tmp);
        mpfr_div(m, tmp2, tmp, MPFR_RNDN);
        //mpfr_printf("M = %.1007Rf\n\n", m);

        mpfr_add_ui(l, l, 545140134, MPFR_RNDN);
        //mpfr_printf("L = %.128Rf\n\n", l);

        mpfr_mul_si(x, x, -262537412640768000, MPFR_RNDN);
        //mpfr_printf("X = %.128Rf\n\n", x);

        mpfr_mul(tmp, m, l, MPFR_RNDN);
        mpfr_div(tmp, tmp, x, MPFR_RNDN);
        mpfr_add(s, s, tmp, MPFR_RNDN);
        //mpfr_printf("S = %.128Rf\n\n", s);

        mpfr_add_ui(k, k, 12, MPFR_RNDN);
        //mpfr_printf("K = %.128Rf\n\n", k);

        //printf("\n");
    }
    mpfr_sqrt_ui(tmp, 10005, MPFR_RNDN);
    mpfr_mul_ui(tmp, tmp, 426880, MPFR_RNDN);
    mpfr_div(*pi, tmp, s, MPFR_RNDN);
    return pi;
}
