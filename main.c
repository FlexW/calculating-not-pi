#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

#include "calc_not_pi.h"

int main(int argc, char *argv[]) {
    int max_k = 70;
    int prec = 2000;
    if (argc == 3) {
        max_k = atoi(argv[1]);
        prec = atoi(argv[2]);
    }
    mpfr_t* notpi = calc_not_pi(max_k, prec);
    mpfr_exp_t exp_t;
    mpfr_printf("%.2000Rf\n", *notpi);
    free(notpi);
    return 0;
}
