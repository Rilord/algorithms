//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include "common.h"

#define ALGO_MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

#define ALGO_MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

ALGO_INLINE int algo_sign(int val) {
    return ((val >> 31) - (-val >> 31));
}

ALGO_INLINE float algo_signf(float val) {
    return (float) ((val > 0.f) - (val < 0.0f));
}

ALGO_INLINE float algo_rad(float deg) {
    return deg * ALGO_PI / 180.f;
}

ALGO_INLINE float algo_pow2(float x) {
    return x * x;
}

ALGO_INLINE float algo_min(float a, float b) {
    if (a < b)
        return a;
    return b;
}

ALGO_INLINE float algo_max(float a, float b) {
    if (a > b)
        return a;
    return b;
}

ALGO_INLINE float algo_clamp(float val, float low, float high) {
    return algo_min(algo_max(val, low), high);
}

ALGO_INLINE float algo_clamp_unit(float val) {
    return algo_clamp(val, 0.0f, 1.0f);
}

ALGO_INLINE float algo_lerp(float t, float v1, float v2) {
    return (1 - t) * v1 + t * v2;
}

ALGO_INLINE float algo_lerp_clamp(float t, float v1, float v2) {
    return algo_lerp(algo_clamp_unit(t), v1, v2);
}

ALGO_INLINE float algo_step(float edge, float x) {
    return (x < edge) ? 0.0f : 1.0f;
}

ALGO_INLINE float algo_smooth_hermite(float t) {
    return t * t * (3.0f - 2.0f * t);
}

ALGO_INLINE float algo_deg (float rad) {
    return (180.f / ALGO_PI) * rad;
}

ALGO_INLINE float log2()

ALGO_INLINE float algo_swapf(float * __restrict a, float * __restrict b) {
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

#endif //ALGORITHMS_UTILS_H
