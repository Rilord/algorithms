//
// Created by kodor on 2/3/22.
//

#ifndef ALGORITHMS_PRIMITIVE_H
#define ALGORITHMS_PRIMITIVE_H

#include "common.h"

enum prim_type { TriangleMesh, Sphere };

typedef struct {
    uint32_t n_triangles,
            n_vertices;
    uint32_t p_size;
    uint32_t m_size;
    uint32_t s_size;
    uint32_t uv_size;
    vec3 *v, n, s;
    vec2 *uv;
    int *face_indices;
} mesh_info;

typedef struct {
    mesh_info *mesh;
} prim_info;

#endif //ALGORITHMS_PRIMITIVE_H
