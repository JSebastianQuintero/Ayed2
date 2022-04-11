#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    unsigned int tmp; 
    FILE * file = fopen(filepath, "r");
    if (file == NULL) return 0;         // check file
    fscanf(file, "%u", &tmp);           // first number = array lenght
    if (tmp>max_size) return 0;         // check array lenght < max_side
    for(unsigned int i=0; i<tmp; i++){
        fscanf(file, "%i", &array[i]);  // reading and saving the array values from file
    }
    return tmp;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    printf("[");
    for(unsigned int i=0; i<length; i++){
        printf(" %i", a[i]);
        if(i<length-1) printf(",");
    }
    printf("]\n");
}

mybool array_is_sorted(int a[], unsigned int length){
    mybool sorted = true;
    for(unsigned int i=1;i<length;i++){
        if(a[i-1]>a[i]) sorted = false; 
    }
    return sorted;
}