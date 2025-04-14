#include "cli.h"
#include "temp_functions.h"
#include "vector.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    CliArguments args = parse_args(argc, argv);

    if (args.show_help) {
        print_usage(argv[0]);
        return 0;
    }

    if (args.filename == NULL) {
        fprintf(stderr, "Error: Input file must be specified with -f\n");
        print_usage(argv[0]);
        return 1;
    }

    FILE *input_file = fopen(args.filename, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open provided file\n");
        return 1;
    }

    char line[30] = "\0";
    size_t len = 0;
    SensorData data;
    Vector *vec = vector_create(sizeof(SensorData), 1024);

    while (readline(input_file, line, sizeof(line), &len)) {
        if (parse_csv_sensor_data(line, &data)) {
            if (!vector_push(vec, &data)) {
                fprintf(stderr, "Error: No more memory to store such a big file data");
                break;
            };
        } else {
            fprintf(stderr, "Warning: failed to parse CSV line: %s\n", line);
        }
    }

    fclose(input_file);

#ifdef DEBUG_LINES
    for (size_t i = 0; i < vec->size; i++) {
        SensorData *data = vector_get(vec, i);
        debug_sensor_data(data);
    }
#endif

    collect_and_print_stats(vec, args.month);

    vector_free(vec);
}
