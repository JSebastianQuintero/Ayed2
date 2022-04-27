#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    // Completar aqui
    if(x >= 0){
        y=x;
    }else{
        y=-x;
    }
}

int main(void) {
    // Completar aqui
    int x=-98, y=0;
    absolute(x, y);
    printf("%d", y);
    return EXIT_SUCCESS;
}

