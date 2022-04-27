#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size){
    FILE *file;
    file = fopen(path, "r");
    unsigned int length=0u;
    while(!feof(file)){
        fscanf(file, "%u '%c'\n", &indexes[length], &letters[length]);
        length++;
        if (length==max_size) break;
    }
    return length;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    
    if (argc < 2) {
        printf("Falta path\n");
        exit(EXIT_FAILURE);
    }
    
    unsigned int length=data_from_file(argv[1], indexes, letters, MAX_SIZE); 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */
    for(unsigned int i=0u; i<length; i++){
        sorted[indexes[i]]=letters[i];
    }
    dump(sorted, length);

    return EXIT_SUCCESS;
}

