#include "statslib.h"
#include <math.h>

void calculate_statistics(FILE *stream, int num_values, StatsResult *result) {
    double sum = 0.0;
    double sum_squared = 0.0;
    double value;
    int count = 0;

    while (count < num_values && fscanf(stream, "%lf", &value) == 1) {
        sum += value;
        sum_squared += value * value;
        count++;
    }

    if (count > 0) {
        result->mean = sum / count;
        result->stddev = sqrt((sum_squared / count) - (result->mean * result->mean));
    } else {
        result->mean = 0.0;
        result->stddev = 0.0;
    }
}
