#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    size_t n = 0u;
    while (*str != '\0'){
        str++;
        n++;        
    }
    return n;
}

char *string_filter(const char *str, char c){
    size_t n = string_length(str);
    char *new = malloc(sizeof(char)), *p = new;
    for(size_t i=0u; i<n;i++){
        if (str[i] != c){
            *p = str[i];
            p++;
        }
    }
    return new;
}