#include "pair.h"
#include <stdlib.h>  

pair_t pair_new(int x, int y){
    pair_t new = malloc(sizeof(struct s_pair_t));
    new->fst = x;
    new->snd = y;
    return new;        
}

int pair_first(pair_t p){
    return p->fst;
}

int pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    return pair_new(p->snd, p->fst);
}

pair_t pair_destroy(pair_t p){
    free(p);
    p=NULL;
    return p;
}