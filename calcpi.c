#include "calcpi.h"

#include <gmp.h>
#include <mpfr.h>

mpfr_t* calc_pi(int max_k) {
    mpfr_t* k, m, l, x, s;
    mpfr_inits(k, m, l, x, s);
    mpfr_set_si(k, 6, MPFR_RNDN);
    mpfr_set_si(m, 1, MPFR_RNDN);
    mpfr_set_si(l, 13591409, MPFR_RNDN);
    mpfr_set_si(x, 1, MPFR_RNDN);
    mpfr_set_si(s, 13591409, MPFR_RNDN);

    for (int i; i <= max_k; i++) {

    }
}
