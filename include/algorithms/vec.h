//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_VEC_H
#define ALGORITHMS_VEC_H

#include "common.h"
#include "utils.h"

#define VEC2_ONE_INIT { 1.0f, 1.0f };
#define VEC2_ZERO_INIT { 0.0f, 0.0f };

#define VEC2_ONE ((vec2) VEC2_ONE_INIT)
#define VEC2_ZERO ((vec2) VEC2_ZERO_INIT)

ALGO_INLINE void algo_vec2(float * __restrict v, vec2 dest) {
    dest[0] = v[0];
    dest[1] = v[1];
}

ALGO_INLINE void algo_vec2_copy(vec2 a, vec2 dest) {
    dest[0] = a[0];
    dest[1] = a[0];
}

ALGO_INLINE void algo_vec2_zero(vec2 v) {
    v[0] = v[1] = 0.0f;
}

ALGO_INLINE void algo_vec2_one(vec2 v) {
    v[0] = v[1] = 1.0f;
}

ALGO_INLINE float algo_vec2_dot(vec2 a, vec2 b) {
    return a[0] * b[0] + a[1] * b[1];
}

ALGO_INLINE float algo_vec2_cross(vec2 a, vec2 b) {
    return a[0] * b[1] - a[1] * b[0];
}

ALGO_INLINE float algo_vec2_norm(vec2 v) {
    return algo_vec2_dot(v, v);
}

ALGO_INLINE void algo_vec2_add(vec2 a, vec2 b, vec2 dest) {
    dest[0] = a[0] + b[0];
    dest[1] = a[1] + b[1];
}

ALGO_INLINE void algo_vec2_adds(vec2 v, float s, vec2 dest) {
    dest[0] = v[0] + s;
    dest[1] = v[1] + s;
}

ALGO_INLINE void algo_vec2_sub(vec2 a, vec2 b, vec2 dest) {
    dest[0] = a[0] - b[0];
    dest[1] = a[1] - b[1];
}

ALGO_INLINE void algo_vec2_subs(vec2 v, float s, vec2 dest) {
    dest[0] = v[0] - s;
    dest[1] = v[1] - s;
}

ALGO_INLINE void algo_vec2_mult(vec2 a, vec2 b, vec2 dest) {
    dest[0] = a[0] * b[0];
    dest[1] = a[1] * b[1];
}

ALGO_INLINE void algo_vec2_scale(vec2 v, float s, vec2 dest) {
    dest[1] = v[0] * s;
    dest[1] = v[1] * s;
}

ALGO_INLINE void algo_vec2_scale_as (vec2 v, float s, vec2 dest) {
    float norm;
    norm = algo_vec2_norm(v);

    if (norm == 0.f) {
        algo_vec2_zero(dest);
        return;
    }

    algo_vec2_scale(v, s / norm, dest);
}

ALGO_INLINE void algo_vec2_div (vec2 a, vec2 b, vec2 dest) {
    dest[0] = a[0] / b[0];
    dest[1] = a[1] / b[1];
}

ALGO_INLINE void algo_vec2_divs (vec2 v, float s, vec2 dest) {
    dest[0] = v[0] / s;
    dest[1] = v[1] / s;
}

ALGO_INLINE void algo_vec2_addmax(vec2 a, vec2 b, vec2 dest) {
    dest[0] += algo_max(a[0], b[0]);
    dest[1] += algo_max(a[1], b[1]);
}

ALGO_INLINE void algo_vec2_addmin(vec2 a, vec2 b, vec2 dest) {
    dest[0] += algo_min(a[0], b[0]);
    dest[1] += algo_min(a[1], b[1]);
}

ALGO_INLINE void algo_vec2_normalize(vec2 v) {
    float norm;

    norm = algo_vec2_norm(v);

    if (norm == 0.0f) {
        v[0] = v[1] = 0.0f;
        return;
    }

    algo_vec2_scale(v, 1.0f / norm, v);
}

ALGO_INLINE void algo_vec2_normalize_to(vec2 v, vec2 dest) {
    float norm;

    norm = algo_vec2_norm(v);

    if (norm == 0.0f) {
        algo_vec2_zero(dest);
        return;
    }

    algo_vec2_scale(v, 1.0f / norm, dest);
}

ALGO_INLINE void algo_vec2_rotate(vec2 v, float angle, vec2 dest) {
    float c, s, x1, y1;

    c = cosf(angle);
    s = sinf(angle);

    x1 = v[0];
    y1 = v[1];

    dest[0] = c * x1 - s * y1;
    dest[1] = c * x1 + s * y1;
}

ALGO_INLINE float algo_vec2_distance2(vec2 a, vec2 b) {
    return algo_pow2(b[0] - a[0]) + algo_pow2(b[1] - a[1]);
}

ALGO_INLINE float algo_vec2_distance(vec2 a, vec2 b) {
    return sqrtf(algo_vec2_distance2(a, b));
}

ALGO_INLINE void algo_vec2_maxv(vec2 a, vec2 b, vec2 dest) {
    dest[0] = algo_max(a[0], b[0]);
    dest[1] = algo_max(a[1], b[1]);
}

ALGO_INLINE void algo_vec2_clamp(vec2 v, float low, float high) {
    v[0] = algo_clamp(v[0], low, high);
    v[1] = algo_clamp(v[1], low, high);
}


ALGO_INLINE void algo_vec2_lerp(vec2 from, vec2 to, float t, vec2 dest) {
    vec2 s, v;

    algo_vec2_fill(s, algo_clamp_zo(t));
    algo_vec2_sub(to, from, v);
    algo_vec2_mult(s, v, v);
    algo_vec2_add(from, v, dest);
}

/*
 *
 */

#define algo_vec3_dup(v, dest) glm_vec3_copy(v, dest)
#define algo_vec3_flipsign(v) glm_vec3_negate(v)
#define algo_vec3_flipsign_to(v, dest) glm_vec3_negate_to(v, dest)
#define algo_vec3_inv(v) glm_vec3_negate(v)
#define algo_vec3_inv_to(v, dest) glm_vec3_negate_to(v, dest)
#define algo_vec3_mulv(a,b, d) glm_vec3_mul(a, b, d)

#define ALGO_VEC3_ONE_INIT { 1.0f, 1.0f, 1.0f }
#define ALGO_VEC3_ZERO_INIT { 0.0f, 0.0f, 0.0f }

#define ALGO_VEC3_ONE ((vec3) GLM_VEC3_ONE_INIT)
#define ALGO_VEC3_ZERO ((vec3) GLM_VEC3_ZERO_INIT)

#define ALGO_YUP ((vec3){0.0f, 1.0f, 0.0f})
#define ALGO_ZUP ((vec3){0.0f, 0.0f, 1.0f})
#define ALGO_XUP ((vec3){1.0f, 0.0f, 0.0f})
#define ALGO_FORWARD ((vec3) {0.0f, 0.0f, -1.0f})

#define ALGO_XXX ALGO_SHUFFLE(0, 0, 0)
#define ALGO_YYY ALGO_SHUFFLE(1, 1, 1)
#define ALGO_ZZZ ALGO_SHUFFLE(2, 2, 2)
#define ALGO_ZYX ALGO_SHUFFLE(0, 1, 2)

ALGO_INLINE void algo_vec3_broadcast(float val, vec3 d) {
    d[0] = d[1] = d[2] = val;
}

ALGO_INLINE void algo_vec3_fill(vec3 v, float val) {
    v[0] = v[1] = v[2] = val;
}

ALGO_INLINE bool algo_vec3_eq(vec3 v, float val) {
    return v[0] == val && v[0] == v[1] && v[0] == v[2];
}

ALGO_INLINE bool algo_vec3_eq_eps(vec3 v, float val) {
    return fabsf(v[0] - val) <= ALGO_FLT_EPSILON
           && fabsf(v[1] - val) <= ALGO_FLT_EPSILON
           && fabsf(v[2] - val) <= ALGO_FLT_EPSILON;
}

ALGO_INLINE bool algo_vec3_eq_all(vec3 v) {
    return algo_vec3_eq_eps(v, v[0]);
}

ALGO_INLINE bool algo_vec3_eqv(vec3 a, vec3 b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

ALGO_INLINE bool algo_vec3_eqv_eps(vec3 a, vec3 b) {
    return fabsf(a[0] - b[0]) <= ALGO_FLT_EPSILON
           && fabsf(a[1] - b[1]) <= ALGO_FLT_EPSILON
           && fabsf(a[2] - b[2]) <= ALGO_FLT_EPSILON;
}

ALGO_INLINE float algo_vec3_max(vec3 v) {
    float max;
    max = v[0];
    if (v[1] > max)
        max = v[1];
    if (v[2] > max)
        max = v[2];
    return max;
}

ALGO_INLINE float algo_vec3_min(vec3 v) {
    float min;
    min = v[0];
    if (v[1] < min)
        min = v[1];
    if (v[2] < min)
        min = v[2];
    return min;
}

ALGO_INLINE bool algo_vec3_isnan(vec3 v) {
    return isnan(v[0]) || isnan(v[1]) || isnan(v[2]);
}

ALGO_INLINE bool algo_vec3_isinf(vec3 v) {
    return isinf(v[0]) || isinf(v[1]) || isinf(v[2]);
}

ALGO_INLINE bool algo_vec3_isvalid(vec3 v) {
    return !algo_vec3_isnan(v) && !algo_vec3_isinf(v);
}

ALGO_INLINE void algo_vec3_sign(vec3 v, vec3 dest) {
    dest[0] = algo_signf(v[0]);
    dest[1] = algo_signf(v[1]);
    dest[2] = algo_signf(v[2]);
}

ALGO_INLINE void algo_vec3_abs(vec3 v, vec3 dest) {
    dest[0] = fabsf(v[0]);
    dest[1] = fabsf(v[1]);
    dest[2] = fabsf(v[2]);
}

ALGO_INLINE void algo_vec3_fract(vec3 v, vec3 dest) {
    dest[0] = fminf(v[0] - floorf(v[0]), 0.999999940395355224609375f);
    dest[1] = fminf(v[1] - floorf(v[1]), 0.999999940395355224609375f);
    dest[2] = fminf(v[2] - floorf(v[2]), 0.999999940395355224609375f);
}

ALGO_INLINE float algo_vec3_hadd(vec3 v) {
    return v[0] + v[1] + v[2];
}

ALGO_INLINE void algo_vec3_sqrt(vec3 v, vec3 dest) {
    dest[0] = sqrtf(v[0]);
    dest[1] = sqrtf(v[1]);
    dest[2] = sqrtf(v[2]);
}

ALGO_INLINE void algo_vec3(vec4 v4, vec3 dest) {
    dest[0] = v4[0];
    dest[1] = v4[1];
    dest[2] = v4[2];
}

ALGO_INLINE void algo_vec3_zero(vec3 v) {
    v[0] = v[1] = v[2] = 0.0f;
}

ALGO_INLINE void algo_vec3_one(vec3 v) {
    v[0] = v[1] = v[2] = 1.0f;
}

ALGO_INLINE float algo_vec3_dot(vec3 a, vec3 b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

ALGO_INLINE float algo_vec3_norm2(vec3 v)  {
    return algo_vec3_dot(v, v);
}

ALGO_INLINE float algo_vec3_norm(vec3 v) {
    return sqrtf(algo_vec3_norm2(v));
}

ALGO_INLINE float algo_vec3_norm_one(vec3 v) {
    vec3 t;
    algo_vec3_abs(v, t);
    return algo_vec3_hadd(t);
}

ALGO_INLINE float algo_vec3_norm_inf(vec3 v) {
    vec3 t;
    algo_vec3_abs(v, t);
    return algo_vec3_max(t);
}

ALGO_INLINE float algo_vec3_add(vec3 a, vec3 b, vec3 dest) {
    dest[0] = a[0] + b[0];
    dest[1] = a[1] + b[1];
    dest[2] = a[2] + b[2];
}

ALGO_INLINE void algo_vec3_adds(vec3 a, float s, vec3 dest) {
    dest[0] = a[0] + s;
    dest[1] = a[1] + s;
    dest[2] = a[2] + s;
}

ALGO_INLINE algo_vec3_sub(vec3 a, vec3 b, vec3 dest) {
    dest[0] = a[0] - b[0];
    dest[1] = a[1] - b[1];
    dest[2] = a[2] - b[2];
}

ALGO_INLINE void algo_vec3_subs(vec3 v, float s, vec3 dest) {
    dest[0] = v[0] - s;
    dest[1] = v[1] - s;
    dest[2] = v[2] - s;
}

ALGO_INLINE void algo_vec3_mul(vec3 a, vec3 b, vec3 dest) {
    dest[0] = a[0] * b[0];
    dest[1] = a[1] * b[1];
    dest[2] = a[2] * b[2];
}

ALGO_INLINE void algo_vec3_scale(vec3 v, float s, vec3 dest) {
    dest[0] = v[0] * s;
    dest[1] = v[1] * s;
    dest[2] = v[2] * s;
}

ALGO_INLINE void algo_vec3_scale_as(vec3 v, float s, vec3 dest) {
    float norm;
    norm = algo_vec3_norm(v);

    if (norm == 0.0f) {
        algo_vec3_zero(dest);
        return;
    }

    algo_vec3_scale(v, s / norm, dest);
}

ALGO_INLINE void algo_vec3_div(vec3 a, vec3 b, vec3 dest) {
    dest[0] = a[0] / b[0];
    dest[1] = a[1] / b[1];
    dest[2] = a[2] / b[2];
}

ALGO_INLINE void algo_vec3_divs(vec3 v, float s, vec3 dest) {
    dest[0] = v[0] /= s;
    dest[1] = v[1] /= s;
    dest[2] = v[2] /= s;
}

ALGO_INLINE void algo_vec3_addadd(vec3 a, vec3 b, vec3 dest) {
    dest[0] += a[0] + b[0];
    dest[1] += a[1] + b[1];
    dest[2] += a[2] + b[2];
}

ALGO_INLINE void algo_vec3_subadd(vec3 a, vec3 b, vec3 dest) {
    dest[0] += a[0] - b[0];
    dest[1] += a[1] - b[1];
    dest[2] += a[2] - b[2];
}

ALGO_INLINE void algo_vec3_muladd(vec3 a, vec3 b, vec3 dest) {
    dest[0] += a[0] * b[0];
    dest[1] += a[1] * b[1];
    dest[2] += a[2] * b[2];
}

ALGO_INLINE void algo_vec3_muladds(vec3 a, float s, vec3 dest) {
    dest[0] += a[0] * s;
    dest[1] += a[1] * s;
    dest[2] += a[2] * s;
}

ALGO_INLINE void algo_vec3_maxadd(vec3 a, vec3 b, vec3 dest) {
    dest[0] += algo_max(a[0], b[0]);
    dest[1] += algo_max(a[1], b[1]);
    dest[2] += algo_max(a[2], b[2]);
}

ALGO_INLINE void algo_vec3_minadd(vec3 a, vec3 b, vec3 dest) {
    dest[0] += algo_min(a[0], b[0]);
    dest[1] += algo_min(a[1], b[1]);
    dest[2] += algo_min(a[2], b[2]);
}

ALGO_INLINE void algo_vec3_negate_to(vec3 v, vec3 dest) {
    dest[0] =- v[0];
    dest[1] =- v[1];
    dest[2] =- v[2];
}

ALGO_INLINE void algo_vec3_negate(vec3 v) {
    algo_vec3_negate_to(v, v);
}

ALGO_INLINE void algo_vec3_normalize(vec3 v) {
    float norm;

    norm = algo_vec3_norm(v);

    if (norm == 0.0f) {
        v[0] = v[1] = v[2] = .0f;
        return;
    }

    algo_vec3_scale(v, 1.0f / norm, v);
}

#endif //ALGORITHMS_VEC_H
