//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_KDTREE_H
#define ALGORITHMS_KDTREE_H

#include "bounds.h"

struct primitive;
struct prim_info;

typedef struct {
    union {
        int flags;
        int n_prims;
        int above_child;
    };
} kd_tree_node;

enum kd_tree_edge_type { Start, End };

typedef struct  {
    float t;
    int prim_num;
    enum kd_tree_edge_type type;
} bound_edge;

struct bound;

struct kdtree_tree {
    int intersect_cost, traversal_cost,
            max_prims;
    struct primitive *primitives;
    int *primitive_indices;
    kd_tree_node *nodes;
    int n_alloced_nodes, next_free_node;
    bounds3 bounds;
    struct prim_info;
};

struct kd_tree_to_do {
    kd_tree_node *node;
    float t_min, t_max;
};

void algo_create_kd_tree(void *prims, struct prim_info *info);

#endif //ALGORITHMS_KDTREE_H
