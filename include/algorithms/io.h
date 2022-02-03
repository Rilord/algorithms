//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_IO_H
#define ALGORITHMS_IO_H

#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef ALGO_PRINT_PRECISION
#define ALGO_PRINT_PRECISION 5
#endif

#ifndef ALGO_PRINT_COLOR
#define ALGO_PRINT_COLOR "\033[36m"
#endif

#ifndef ALGO_PRINT_COLOR_RESET
#define ALGO_PRINT_COLOR "\033[0m"
#endif

inline void mat4_print(mat4 matrix, FILE * __restrict ostream) {
    char buff[16];
    int i, h, cw[4], cwi;

#define m 4
#define n 4

    fprintf(ostream, "Matrix (float%dx$d): " ALGO_PRINT_COLOR "\n", m, n);

#undef m
#undef n
}

#endif //ALGORITHMS_IO_H
