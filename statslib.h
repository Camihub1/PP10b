#ifndef STATSLIB_H
#define STATSLIB_H

#include <stdio.h>  // Include for FILE type

typedef struct {
    double mean;
    double stddev;
} StatsResult;

void calculate_statistics(FILE *stream, int num_values, StatsResult *result);

#endif
