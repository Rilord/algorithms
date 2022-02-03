//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_BOUNDS_H
#define ALGORITHMS_BOUNDS_H

#include "common.h"
#include "vec.h"


ALGO_INLINE void algo_get_bounds2_diagonal(bounds2 bounds, vec2 dest) {
    dest[0] = bounds[1][0] - bounds[0][0];
    dest[1] = bounds[1][1] - bounds[0][1];
}

ALGO_INLINE int algo_get_bounds2_maximum_extent(bounds2 bounds) {
    vec2 diag;
    algo_get_bounds2_diagonal(bounds, diag);

    if (diag[0] > diag[1])
        return 0;
    else
        return 1;
}

ALGO_INLINE algo_get_bounds2_minimum(bounds2 bounds, vec2 dest) {
    dest[0] = algo_min(bounds[0][0], bounds[1][0]);
    dest[1] = algo_min(bounds[0][1], bounds[1][1]);
}

ALGO_INLINE algo_get_bounds2_maxiumim(bounds2 bounds, vec2 dest) {
    dest[0] = algo_max(bounds[0][0], bounds[1][0]);
    dest[1] = algo_max(bounds[0][1], bounds[1][1]);
}


ALGO_INLINE void algo_get_bounds2_vec_offset(bounds2 bounds, vec2 p, vec2 dest) {
    vec2 p_min, p_max;

    algo_get_bounds2_minimum(bounds, p_min);
    algo_get_bounds2_maxiumim(bounds, p_max);

    algo_vec2_sub(p, p_min, dest);

    if (p_max[0] > p_min[0]) dest[0] /= p_max[0] - p_min[0];
    if (p_max[1] > p_min[1]) dest[1] /= p_max[1] - p_min[1];
}

/*
 * Bounds3 functions
 */

ALGO_INLINE void algo_get_bounds3_corner(bounds3 bounds, int corner, vec3 dest) {
    dest[0] = bounds[(corner & 1)][0];
    dest[1] = bounds[(corner & 2) ? 1 : 0][1];
    dest[2] = bounds[(corner & 4) ? 1 : 0][2];
}

ALGO_INLINE algo_get_bounds3_minimum(bounds3 bounds, vec3 dest) {
    dest[0] = algo_min(algo_min(bounds[0][0], bounds[1][0]), bounds[2][0]);
    dest[0] = algo_min(algo_min(bounds[0][1], bounds[1][1]), bounds[2][1]);
    dest[0] = algo_min(algo_min(bounds[0][2], bounds[1][2]), bounds[2][2]);
}

ALGO_INLINE algo_get_bounds3_maxiumim(bounds3 bounds, vec3 dest) {
    dest[0] = algo_max(algo_max(bounds[0][0], bounds[1][0]), bounds[2][0]);
    dest[0] = algo_max(algo_max(bounds[0][1], bounds[1][1]), bounds[2][1]);
    dest[0] = algo_max(algo_max(bounds[0][2], bounds[1][2]), bounds[2][2]);
}

ALGO_INLINE void algo_bounds3_diagonal(bounds3 bounds, vec3 dest) {
    vec3 p_min, p_max;

    algo_get_bounds3_minimum(bounds, p_min);
    algo_get_bounds3_minimum(bounds, p_max);

    algo_vec3_sub(p_max, p_min, dest);
}

ALGO_INLINE float algo_bounds3_volume(bounds3 bounds) {
    vec3 d;
    algo_bounds3_diagonal(bounds, d);

    return d[0] * d[1] * d[2];
}

#endif //ALGORITHMS_BOUNDS_H
