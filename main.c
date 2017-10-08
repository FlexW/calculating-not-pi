#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

#include "calc_not_pi.h"

bool is_integer(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    int max_k = 70;
    int prec = 2000;
    if (argc != 3) {
        printf("Calculating not PI using the Chudnovsky algorithm.\n");
        printf("Usage: %s ITERATIONS PRECISION\n", argv[0]);
        printf("Example %s 2000 10000\n", argv[0]);
        return 1;
    }
    if (!(is_integer(argv[1]) && is_integer(argv[2]))) {
        printf("Just integers allowed as input.\n");
        return 1;
    }
    max_k = atoi(argv[1]);
    prec = atoi(argv[2]);
    mpfr_t* notpi = calc_not_pi(max_k, prec);
    mpfr_printf("%.*Rf\n", prec, *notpi);
    free(notpi);
    return 0;
}
