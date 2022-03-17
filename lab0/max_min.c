#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = array[0]; // el primer elemento del array va a ser el maximo y el minimo por ahora
    result.min_value = array[0];
    // IMPLEMENTAR
    for(unsigned int i=0; i<length;i++){
        if (array[i]>result.max_value){     // se encontro un elemento mas grande
            result.max_value = array[i];    // guardo el valor nuevo
            result.max_position = i;        // guardo su posicion en array
        }
        if (array[i]<result.min_value){
            result.min_value = array[i];
            result.min_position = i;
        }
    }
    return result;
}

int main(void)
{
    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };

    // PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO.
    for(unsigned int i=0; i<ARRAY_SIZE;i++){    // loop para rellenar el array
        printf("array[%d]: ", i);               // print 
        scanf("%d", &array[i]);                 // guardo el input en el array
    }

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}
