#include <assert.h>
#include <stdlib.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

#include <stdio.h>


static type_elem choose(cost_t *costs, set no_visit){
    set aux_set = set_copy(no_visit);
    type_elem aux_elem, aux_min;
    cost_t min_value = cost_inf();

    while(!set_is_empty(aux_set)){
        aux_elem = set_get(aux_set);
        aux_set = set_elim(aux_set, aux_elem);
        if (cost_le(costs[aux_elem], min_value)){
            min_value = costs[aux_elem];
            aux_min = aux_elem;
        }
    }

    aux_set = set_destroy(aux_set);
    return aux_min;
} 

cost_t *dijkstra(graph_t graph, vertex_t init) {
    cost_t *res = calloc(graph_max_vertexs(graph), sizeof(cost_t));
    set no_visit = set_empty();
    type_elem e;
    for(unsigned int i=0u; i < graph_max_vertexs(graph); i++){
        res[i] = cost_inf();
        no_visit = set_add(no_visit, i);
    }
    
    res[init] = 0;
    while(!set_is_empty(no_visit)){
        e = choose(res, no_visit);
        no_visit = set_elim(no_visit, e);

        // for i in no_visit
        set no_visit_copy = set_copy(no_visit);
        while(!set_is_empty(no_visit_copy)){
            type_elem e_aux = set_get(no_visit_copy);
            no_visit_copy = set_elim(no_visit_copy, e_aux);
            cost_t new_path = cost_sum(res[e], graph_get_cost(graph, e, e_aux));
            if(cost_le(res[e_aux], new_path)){
                res[e_aux] = res[e_aux];
            }else{
                res[e_aux] = new_path;
            }
        }
        no_visit_copy = set_destroy(no_visit_copy);
    }

    no_visit = set_destroy(no_visit);
    return res;
}

