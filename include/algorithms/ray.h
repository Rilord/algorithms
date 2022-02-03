//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_RAY_H
#define ALGORITHMS_RAY_H

#include "common.h"

typedef struct ray {
    vec3 o, d;
    float t_max;
};

#endif //ALGORITHMS_RAY_H
