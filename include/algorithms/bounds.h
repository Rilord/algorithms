//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_BOUNDS_H
#define ALGORITHMS_BOUNDS_H

#include "common.h"

inline void get_bounds2_diagonal(bounds2 bounds, vec2 dest) {
    dest[0] = bounds[1][0] - bounds[0][0];
    dest[1] = bounds[1][1] - bounds[0][1];
}

inline int vec2 get_bounds2_maximum_extent(bounds2 )

#endif //ALGORITHMS_BOUNDS_H
