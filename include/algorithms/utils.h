//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include "common.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

inline int sign(int val) {
    return ((val >> 31) - (-val >> 31));
}

#endif //ALGORITHMS_UTILS_H
