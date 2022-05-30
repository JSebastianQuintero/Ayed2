/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 3 ;

Flight flight_from_file(FILE* file, char code)
{
    Flight flight;
    flight.code = code;

    /* COMPLETAR */
    int res = fscanf(file, "%u %u %u\n", &flight.type, &flight.hour, &flight.passengers_amount);
    if (res != AMOUNT_OF_FLIGHT_VARS) {
      fprintf(stderr, "Invalid file. in flight code %d\n", code);
      exit(EXIT_FAILURE);
    }
    return flight;
}
