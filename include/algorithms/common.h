//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_COMMON_H
#define ALGORITHMS_COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#define ALGO_EXPORT __attribute((visibility("default")))
#define ALGO_INLINE __attribute((always_inline))

#define ALGO_SHUFFLE4(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2) | (w))
#define ALGO_SHUFFLE3(z, y, x) (((z) << 4) | ((y) << 2) | (x))



#include "types.h"

#ifndef ALGO_USE_DEFAULT_EPSILON
# ifndef ALGO_FLT_EPSILON
# define ALGO_FLT_EPSILON 1e-5
# endif
#else
# define ALGO_FLT_EPSILON FLT_EPSILON
#endif

#define ALGO_CLIP_CONTROL_ZO_BIT (1 << 0)
#define ALGO_CLIP_CONTROL_NO_BIT (1 << 1)
#define ALGO_CLIP_CONTROL_LH_BIT (1 << 2)
#define ALGO_CLIP_CONTROL_RH_BIT (1 << 3)

#define ALGO_CLIP_CONTROL_LH_ZO (ALGO_CLIP_CONTROL_LH_BIT | ALGO_CLIP_CONTROL_ZO_BIT)
#define ALGO_CLIP_CONTROL_LH_NO (ALGO_CLIP_CONTROL_LH_BIT | ALGO_CLIP_CONTROL_NO_BIT)
#define ALGO_CLIP_CONTROL_RH_ZO (ALGO_CLIP_CONTROL_RH_BIT | ALGO_CLIP_CONTROL_ZO_BIT)
#define ALGO_CLIP_CONTROL_RH_NO (ALGO_CLIP_CONTROL_RH_BIT | ALGO_CLIP_CONTROL_NO_BIT)

#endif //ALGORITHMS_COMMON_H
