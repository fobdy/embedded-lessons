#include "cli.h"
#include <getopt.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *app_name) {
    printf("Usage: %s [options]\n", app_name);
    printf("Options:\n");
    printf("  -h          Display this help message\n");
    printf("  -f filename Specify input file\n");
    printf("  -m month    Filter data for the specified month (1-12)\n");
}

CliArguments parse_args(int argc, char *argv[]) {
    CliArguments args = {false, NULL, -1};

    int opt;
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt) {
        case 'h':
            args.show_help = true;
            break;

        case 'f':
            args.filename = optarg;
            break;

        case 'm': {
            if ((sscanf(optarg, "%" SCNd8, &args.month) != 1) ||
                (args.month < 1 || args.month > 12)) {
                fprintf(stderr, "Error: Invalid number for -m option\n");
                exit(1);
            }
        } break;

        case '?':
            print_usage(argv[0]);
            exit(1);

        default:
            fprintf(stderr, "Error: Unexpected error processing options\n");
            exit(1);
        }
    }

    return args;
}