#include <stdio.h>
#include "statslib.h"

#define NUM_VALUES 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    StatsResult result;
    calculate_statistics(input_file, NUM_VALUES, &result);

    printf("Mean: %.2f\n", result.mean);
    printf("Standard Deviation: %.2f\n", result.stddev);

    fclose(input_file);
    return 0;
}
