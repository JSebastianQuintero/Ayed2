#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node * list;
typedef int list_elem;

struct _node {
    list_elem elem;
    struct _node *next;
};

list empty(void){
    return NULL;
}

list addl(list l, list_elem e){
    list p = malloc(sizeof(struct _node));
    p->elem = e;
    p->next = l;
    return p;
}

void destroy(list l){
    list p = l;
    while (p!=NULL){
        l=l->next;
        free(p);
        p=l;
    }    
}

bool is_empty(list l){
    return (l==NULL);
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    list p = l->next;
    free(l);
    return p;
}

void addr(list l, list_elem e){        
    list new = malloc(sizeof(struct _node)), lp;
    new -> elem = e;
    new -> next = NULL;
    lp = l;
    while(!is_empty(lp)){
        lp = lp->next;
    }
    lp = new;
}

unsigned int length(list l){
    list p=l;
    unsigned int n = 0u;
    while (p!=NULL){
        n++;
        p = p->next;
    }
    return n;
}

list concat(list l1, list l2){
    list p = l1;
    while (p->next!=NULL){
        p=p->next;
    }
    destroy(p->next);
    p->next = l2;
    return l1;
}

list index(list l, unsigned int i){
    assert(length(l)>i);
    list p=l;
    while(i>0){
        i--;
        p=p->next;
    }
    return p;
}

void take(list l, unsigned int n){
    list p = l;
    while (n>0){
        n--;
        p = p->next;
    }
    destroy(p);    
}

list drop(list l, unsigned int n){
    while (n>0){
        l = tail(l);
        n--;
    }
    return l;
}

list copy_list(list l){
    list new = empty(), p=l;
    new = addl(new, p->elem);
    p = p->next;
    while (p!=NULL){
        addr(new, p->elem);
        p = p->next;
    }
    return new;
}