#ifndef CLI_H
#define CLI_H
#include <stdbool.h>
#include <stdint.h>

/**
 * Command line options
 */
typedef struct CliArguments {
    bool show_help;
    char *filename;
    int8_t month;
} CliArguments;

CliArguments parse_args(int argc, char *argv[]);
void print_usage(const char *app_name);

#endif