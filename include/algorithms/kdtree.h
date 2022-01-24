//
// Created by kodor on 1/24/22.
//

#ifndef ALGORITHMS_KDTREE_H
#define ALGORITHMS_KDTREE_H

#include "bounds.h"

struct kd_tree_node;
struct bound;

struct kdtree_tree {
    int intersect_cost,
    traversal_cost, max_prims;
    kd_tree_node *nodes;
    int n_alloced_nodes, next_free_node;


};

#endif //ALGORITHMS_KDTREE_H
