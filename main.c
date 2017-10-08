#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

#include "calcpi.h"

int main(int argc, char *argv[]) {
    mpfr_t* pi;
    if (argc != 3) {
        pi = calc_pi(70, 2000);
    }
    else {
        int max_k = atoi(argv[1]);
        int prec = atoi(argv[2]);
        pi = calc_pi(max_k, prec);
    }
    mpfr_exp_t exp_t;
    mpfr_printf("%.2000Rf\n", *pi);
    return 0;
}
