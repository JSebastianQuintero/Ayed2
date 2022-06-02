#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct _node * list;
typedef int list_elem;

list empty(void);

list addl(list l, list_elem e);

void destroy(list l);

bool is_empty(list l);

list_elem head(list l);

list tail(list l);

void addr(list l, list_elem e);

unsigned int length(list l);

list concat(list l1, list l2);

list index(list l, unsigned int i);

void take(list l, unsigned int n);

list drop(list l, unsigned int n);

list copy_list(list l);

#endif