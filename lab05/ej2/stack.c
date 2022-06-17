#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e) {
    if (s->size<s->capacity){
        s->elems[s->size] = e;
    }else{
        s->elems = realloc(s->elems, sizeof(stack_elem)*(s->capacity * 2));
        s->elems[s->size] = e; 
    }
    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack p=s->next;
    free(s);
    s=NULL;
    return p;
}

unsigned int stack_size(stack s){
    return s->length;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return (s==NULL);
}

stack_elem *stack_to_array(stack s){
    unsigned int n = stack_size(s);
    stack_elem *a = malloc(sizeof(stack_elem)*n);
    for (unsigned int i = 1; i <= n; i++){
        a[n-i]=stack_top(s);
        s = stack_pop(s);
    }
    return a;
}

stack stack_destroy(stack s){
    stack p=s;
    while (p!=NULL){
        s=p->next;
        free(p);
        p=NULL;
        p=s;
    }
    return p;
}